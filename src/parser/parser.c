/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:10:32 by tpoungla          #+#    #+#             */
/*   Updated: 2024/04/25 18:31:54 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**init_map(char **smap, int width, int height)
{
	char	**map;
	int		i;

	i = 0;
	(void)width;
	map = (char **)malloc(sizeof(char *) * (height + 1));
	map[height] = NULL;
	while (i < height)
	{
		map[i] = ft_strdup(smap[i + 6]);
		i++;
	}
	free2d(smap);
	return (map);
}

void	print_map(char **map)
{
	int	i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		printf("[");
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("]\n");
		i++;
	}
}

void	print_map_data(t_parser_data *res)
{
	printf("NO : [%s]\n", res->north_texture);
	printf("SO : [%s]\n", res->south_texture);
	printf("WE : [%s]\n", res->west_texture);
	printf("EA : [%s]\n", res->east_texture);
    printf("floor : [%u]\n", res->floor_color);
	printf("ceil : [%u]\n", res->ceil_color);
}

char	**file_reader(int fd)
{
	char	*tmp;
	char	*chdata;
	char	**map;
	char	*buffer;
	int		read_count;

	read_count = 1;
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	buffer[BUFFER_SIZE] = '\0';
	chdata = ft_calloc(sizeof(char), 1);
	while (read_count > 0)
	{
		tmp = chdata;
		read_count = read(fd, buffer, BUFFER_SIZE);
		chdata = ft_strjoin(tmp, buffer);
		buffer[read_count] = '\0';
		if (!(buffer[0] > 31 && buffer[0] < 128) && buffer[0] != '\n' && read_count > 0)
		{
			read_count = 0;
		}	//printf("<%c> not printable!!!!\n", buffer[0]);
		free(tmp);
		// printf("-------------------------done read-------------------------\n");
	}
	free(buffer);
	if (read_count < -1)
		perror("FILE READER : ");
	if (scanner(chdata) == 0 || !ft_strlen(chdata))
	{
		free(chdata);
		return(NULL);
	}
	map = ft_split(chdata, '\n');
	free(chdata);
	return (map);
}

t_parser_data	*main_parser(char *file_name)
{
	t_parser_data	*res;
	int				fd;
	char			**data;

	res = ft_calloc(sizeof(t_parser_data), 1);
	if (!is_file_valid(file_name, ".cub"))
	{
		free(res);
		return (0);
	}
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		free(res);
		return (0);
	}
	data = file_reader(fd);
	if (data == NULL)
	{
		printf("Data in file not good\n");
		free(res);
		return (NULL);
	}
	if (count_value_line(data) == -1)
	{
		printf("incorrect element no.\n");
		free(res);
		free2d(data);
		return (NULL);
	}
	if (!check_resource(data, res))
	{
		printf("incorrect value no.\n");
		free2d(data);
		free_parser(res);
		return (NULL);
	}
	if (!src_checker(res))
	{
		printf("Texture element: cant open or null, not .png extention\n");
		free2d(data);
		free_parser(res);
		return (NULL);
	}
	res->height = find_height(data);
	res->width = find_width(data);
	if (res->height == 0 || res->width == 0)
	{
		printf("empty map\n");
		free2d(data);
		free_parser(res);
		return (NULL);
	}
	res->maps_data = init_map(data, find_width(data), find_height(data));
	if (!scan4player(res->maps_data))
	{
		printf("incorrect player no.\n");
		free_parser(res);
		return (NULL);
	}
	if (!border_checker(res->maps_data))
	{
		printf("border not ok\n");
		free_parser(res);
		return (NULL);
	}
	close(fd);
	print_map_data(res);
	print_map(res->maps_data);
	return (res);
}

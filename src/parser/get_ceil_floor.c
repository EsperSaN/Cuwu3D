#include "parser.h"

int	get_ceil_floor(char *str, t_parser_data *res, char mode)
{
	int		i;
	int		color[3];
	int		rgb;
	char	**num;

	num = ft_split(str, ',');
	i = 0;
	while (num[i])
	{
		if (ft_atoi(num[i]) < 0 || ft_atoi(num[i]) > 255)
			return (free2d(num), 0);
		i++;
	}
	if (i != 3)
		return (free2d(num), 0);
	i = -1;
	while (num[++i])
		color[i] = ft_atoi(num[i]);
	rgb = get_rgba(color[0], color[1], color[2], 255);
	if (mode == 'c' && res->ceil_color == 0)
		res->ceil_color = rgb;
	else if (mode == 'f' && res->floor_color == 0)
		res->floor_color = rgb;
	free2d(num);
	return (1);
}

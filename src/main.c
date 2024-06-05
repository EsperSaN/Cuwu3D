/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:25:08 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/05 16:54:32 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **av)
{
	t_data	*d;

	if (ac != 2)
		return (puterror(WRG_ARG_NO), 1);
	d = ft_calloc(sizeof(t_data), 1);
	if (d == NULL)
		return (puterror("Malloc::faill to alloc the thing!!!"), 1);
	d->parser_data = main_parser(av[1]);
	if (d->parser_data == NULL)
		return (printf("Invalid Data in file\n"), terminate_and_cleanup(&d), 1);
	if (!set_from_parser_data(d))
		return (terminate_and_cleanup(&d), 1);
	if (prepare_render(d) == false)
		return (terminate_and_cleanup(&d), 1);
	mlx_loop_hook(d->mlx, key_hook, (void *)d);
	mlx_loop(d->mlx);
	terminate_and_cleanup(&d);
	return (0);
}

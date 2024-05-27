/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:21:53 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/21 16:03:37 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
#define RENDER_H

#include "cube.h"

bool                set_from_parser_data(t_data *data);
t_maps_data         *set_maps_data(t_data *data);
t_texture_assets    *set_texture_assets(t_data *data);
void                key_hook(void *data);
void	            draw_square(mlx_image_t *image, t_int_point pos, int size, int color);
void                draw_square_center(mlx_image_t *image, t_int_point pos, int size, int color);
void	            clear_image(mlx_image_t *frm, int color);
void	            draw_maps(t_data *d, mlx_image_t *image, t_maps_data *maps_data);
bool                prepare_render(t_data *data);
void                main_render(void *d);
int                 draw_line(mlx_image_t *img, t_int_point head, t_int_point tail, int color);


#endif
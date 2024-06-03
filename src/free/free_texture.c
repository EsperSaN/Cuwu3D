/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:34:06 by wave              #+#    #+#             */
/*   Updated: 2024/06/02 17:34:10 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

t_texture	*free_texture(t_texture *data)
{
	int		height;

	height = 0;
	if (data != NULL)
	{
		while (height < data->height)
		{
			free(data->pixel_array[height]);
			data->pixel_array[height] = NULL;
			height++;
		}
		free(data->pixel_array);
		free(data);
	}
	return (NULL);
}

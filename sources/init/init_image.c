/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:12:31 by lorphan           #+#    #+#             */
/*   Updated: 2022/03/13 19:46:27 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_image	*init_image(t_minirt *minirt)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->img = mlx_new_image(minirt->window->mlx,
			WINDOW_HEIGHT, WINDOW_HEIGHT);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	if (!image->img || !image->addr)
	{
		free(image);
		return (NULL);
	}
	return (image);
}
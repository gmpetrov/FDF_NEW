/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 16:35:05 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/04 16:36:18 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		img_pixel_put(t_env *e, int x, int y, int color)
{
	unsigned int	new_color;
	int				i;

	if (x >= WIDTH || y >= HEIGTH || x < 0 || y < 0)
		return (-1);
	new_color = mlx_get_color_value(e->mlx, color);
	i = x * 4 + y * e->size_line;
	e->data[i] = (new_color & 0xFF);
	e->data[i + 1] = (new_color & 0xFF00) >> 8;
	e->data[i + 2] = (new_color & 0xFF0000) >> 16;
	return (0);
}

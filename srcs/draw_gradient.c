/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gradient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:55:25 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/04 16:48:46 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_gradient(t_env *e)
{
	int			x;
	int			y;
	t_color		c;

	c.r = 0xFF;
	c.g = 0x00;
	c.b = 0x42;
	x = -1;
	y = -1;
	while (++y < HEIGTH)
	{
		while (++x < WIDTH)
			img_pixel_put(e, x, y, e->color);
		if (y % 2 == 0)
		{
			if (c.r < 0xFF)
				c.r++;
			if (c.g < 0xFF)
				c.g++;
			if (c.b < 0xFF)
				c.b++;
		}
		e->color = (c.b) + (c.g << 8) + (c.r << 16);
		x = 0;
	}
}

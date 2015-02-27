/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 12:05:19 by gmp               #+#    #+#             */
/*   Updated: 2015/02/27 12:07:24 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		img_pixel_put(t_env *e, int x, int y, int color)
{
	unsigned int	new_color;
	int	i;

	if (x >= WIDTH || y >= HEIGTH || x < 0 || y < 0)
		return -1;
	new_color = mlx_get_color_value(e->mlx, color);
	i = x * 4 + y * e->size_line;
	e->data[i] = (new_color & 0xFF);
	e->data[i + 1] = (new_color & 0xFF00) >> 8;
	e->data[i + 2] = (new_color & 0xFF0000) >> 16;
	return 0;
}

void	swap_pos(int *x1, int *y1, int *x2, int *y2)
{
	int tmp_x;
	int tmp_y;

	tmp_x = *x2;
	tmp_y = *y2;
	*x1 = *x2;
	*y1 = *y2;
	*y2 = tmp_y;
	*x2 = tmp_x;	
}

void 	clearImg(t_env *e)
{
	int 	x;
	int 	y;

	x = 0;
	y = 0;
	while (y < HEIGTH)
	{
		while (x < WIDTH)
		{
			img_pixel_put(e, x, y, 0x000000);
			x++;
		}
		x = 0;
		y++;
	}
}
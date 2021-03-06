/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 12:05:19 by gmp               #+#    #+#             */
/*   Updated: 2015/03/04 16:37:31 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	clear_img(t_env *e)
{
	int		x;
	int		y;

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

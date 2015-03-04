/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_isometric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 11:42:20 by gmp               #+#    #+#             */
/*   Updated: 2015/03/04 13:38:00 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		iso_line_1(t_env *e, int x, int y)
{
	t_point a;
	t_point b;

	e->x_i_1 = ((x) * e->cte) - (e->cte * (y + 1));
	e->y_i_1 = -(e->map[y + 1][x + 1]) + \
		(((e->cte / 2) * x) + ((e->cte / 2) * (y + 1)));
	e->x_i_2 = (x * e->cte) - (e->cte * y);
	e->y_i_2 = -(e->map[y][x + 1]) + (((e->cte / 2) * x) + ((e->cte / 2) * y));
	a.x = (e->x_i_1 * e->scale) + e->origin_x;
	a.y = (e->y_i_1 * e->scale) + e->origin_y;
	a.z = e->map[y + 1][x + 1];
	b.x = (e->x_i_2 * e->scale) + e->origin_x;
	b.y = (e->y_i_2 * e->scale) + e->origin_y;
	b.z = e->map[y][x + 1];
	draw_line_mlx(e, a, b);
}

static void		iso_line_2(t_env *e, int x, int y)
{
	t_point a;
	t_point b;

	e->x_i_1 = ((x) * e->cte) - (e->cte * (y + 1));
	e->y_i_1 = -(e->map[y + 1][x + 1]) + (((e->cte / 2) * x) \
		+ ((e->cte / 2) * (y + 1)));
	e->x_i_2 = ((x + 1) * e->cte) - (e->cte * (y + 1));
	e->y_i_2 = -(e->map[y + 1][x + 2]) + (((e->cte / 2) * \
		(x + 1)) + ((e->cte / 2) * (y + 1)));
	a.x = (e->x_i_1 * e->scale) + e->origin_x;
	a.y = (e->y_i_1 * e->scale) + e->origin_y;
	a.z = e->map[y + 1][x + 1];
	b.x = (e->x_i_2 * e->scale) + e->origin_x;
	b.y = (e->y_i_2 * e->scale) + e->origin_y;
	b.z = e->map[y + 1][x + 2];
	draw_line_mlx(e, a, b);
}

static void		iso_line_3(t_env *e, int x, int y)
{
	t_point a;
	t_point b;

	e->x_i_1 = ((x + 1) * e->cte) - (e->cte * y);
	e->y_i_1 = -(e->map[y][x + 2]) + (((e->cte / 2) * (x + 1)) + \
		((e->cte / 2) * y));
	e->x_i_2 = ((x + 1) * e->cte) - (e->cte * (y + 1));
	e->y_i_2 = -(e->map[y + 1][x + 2]) + (((e->cte / 2) * \
		(x + 1)) + ((e->cte / 2) * (y + 1)));
	a.x = (e->x_i_1 * e->scale) + e->origin_x;
	a.y = (e->y_i_1 * e->scale) + e->origin_y;
	a.z = e->map[y + 1][x + 2];
	b.x = (e->x_i_2 * e->scale) + e->origin_x;
	b.y = (e->y_i_2 * e->scale) + e->origin_y;
	b.z = e->map[y][x + 2];
	draw_line_mlx(e, a, b);
}

static void		iso_line_4(t_env *e, int x, int y)
{
	t_point a;
	t_point b;

	e->x_i_1 = x * e->cte - (e->cte * y);
	e->y_i_1 = -(e->map[y][x + 1]) + (((e->cte / 2) * x) + ((e->cte / 2) * y));
	e->x_i_2 = (x + 1) * e->cte - e->cte * y;
	e->y_i_2 = -(e->map[y][x + 2]) + (((e->cte / 2) * \
		(x + 1)) + ((e->cte / 2) * y));
	a.x = (e->x_i_1 * e->scale) + e->origin_x;
	a.y = (e->y_i_1 * e->scale) + e->origin_y;
	a.z = e->map[y][x + 1];
	b.x = (e->x_i_2 * e->scale) + e->origin_x;
	b.y = (e->y_i_2 * e->scale) + e->origin_y;
	b.z = e->map[y][x + 2];
	draw_line_mlx(e, a, b);
}

void			draw_isometric(t_env *e)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	while (y < e->map_heigth - 1)
	{
		while (x < e->map[y][0] - 1)
		{
			iso_line_1(e, x, y);
			iso_line_2(e, x, y);
			iso_line_3(e, x, y);
			iso_line_4(e, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

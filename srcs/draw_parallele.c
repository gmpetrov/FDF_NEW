/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_parallele.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 11:57:28 by gmp               #+#    #+#             */
/*   Updated: 2015/02/27 12:06:17 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 	parallele_line_1(t_env *e, int x, int y);
void 	parallele_line_2(t_env *e, int x, int y);
void 	parallele_line_3(t_env *e, int x, int y);
void 	parallele_line_4(t_env *e, int x, int y);

void 	drawParallele(t_env *e)
{	
	int 	y;
	int 	x;

	x = 0;
	y = 0;
	while (y < e->map_heigth - 1){
		while (x < e->map[y][0] - 1)
		{
			parallele_line_1(e, x, y);
			parallele_line_2(e, x, y);
			parallele_line_3(e, x, y);
			parallele_line_4(e, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void 	parallele_line_1(t_env *e, int x, int y)
{
	t_point a;
	t_point b;

	e->x_i_1 = x + ((e->cte / 6) * e->map[y][x + 1]);
	e->y_i_1 = y + (((e->cte / 6)/2) * (e->map[y][x + 1]));
	e->x_i_2 = (x + 1) + ((e->cte / 6) * e->map[y][x + 2]);
	e->y_i_2 = (y) + (((e->cte / 6)/2) * (e->map[y][x + 2]));
	a.x = (e->x_i_1 * e->scale) + e->origin_x;
	a.y = (e->y_i_1 * e->scale) + e->origin_y;
	a.z = e->map[y][x + 1];
	b.x = (e->x_i_2 * e->scale) + e->origin_x;
	b.y = (e->y_i_2 * e->scale) + e->origin_y;
	b.z = e->map[y][x + 2];
	draw_line_mlx(e, a, b);
}

void 	parallele_line_2(t_env *e, int x, int y)
{
	t_point a;
	t_point b;

	e->x_i_1 = x + ((e->cte / 6) * e->map[y][x + 1]);
	e->y_i_1 = y + (((e->cte / 6)/2) * (e->map[y][x + 1]));
	e->x_i_2 = (x) + ((e->cte / 6) * e->map[y + 1][x + 1]);
	e->y_i_2 = (y + 1) + (((e->cte / 6)/2) * (e->map[y + 1][x + 1]));
	a.x = (e->x_i_1 * e->scale) + e->origin_x;
	a.y = (e->y_i_1 * e->scale) + e->origin_y;
	a.z = e->map[y][x + 1];
	b.x = (e->x_i_2 * e->scale) + e->origin_x;
	b.y = (e->y_i_2 * e->scale) + e->origin_y;
	b.z = e->map[y + 1][x + 1];
	draw_line_mlx(e, a, b);
}

void 	parallele_line_3(t_env *e, int x, int y)
{
	t_point a;
	t_point b;

	e->x_i_1 = x + ((e->cte / 6) * e->map[y + 1][x + 1]);
	e->y_i_1 = y + 1 + (((e->cte / 6)/2) * (e->map[y + 1][x + 1]));
	e->x_i_2 = (x + 1) + ((e->cte / 6) * e->map[y + 1][x + 2]);
	e->y_i_2 = (y + 1) + (((e->cte / 6)/2) * (e->map[y + 1][x + 2]));
	a.x = (e->x_i_1 * e->scale) + e->origin_x;
	a.y = (e->y_i_1 * e->scale) + e->origin_y;
	a.z = e->map[y + 1][x + 1];
	b.x = (e->x_i_2 * e->scale) + e->origin_x;
	b.y = (e->y_i_2 * e->scale) + e->origin_y;
	b.z = e->map[y + 1][x + 2];
	draw_line_mlx(e, a, b);
}

void 	parallele_line_4(t_env *e, int x, int y)
{
	t_point a;
	t_point b;

	e->x_i_1 = (x + 1) + ((e->cte / 6) * e->map[y][x + 2]);
	e->y_i_1 = (y) + (((e->cte / 6)/2) * (e->map[y][x + 2]));
	e->x_i_2 = (x + 1) + ((e->cte / 6) * e->map[y + 1][x + 2]);
	e->y_i_2 = (y + 1) + (((e->cte / 6)/2) * (e->map[y + 1][x + 2]));
	a.x = (e->x_i_1 * e->scale) + e->origin_x;
	a.y = (e->y_i_1 * e->scale) + e->origin_y;
	a.z = e->map[y][x + 2];
	b.x = (e->x_i_2 * e->scale) + e->origin_x;
	b.y = (e->y_i_2 * e->scale) + e->origin_y;
	b.z = e->map[y + 1][x + 2];
	draw_line_mlx(e, a, b);
}

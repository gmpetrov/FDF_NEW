/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 11:37:50 by gmp               #+#    #+#             */
/*   Updated: 2015/02/27 12:25:45 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 	case1(t_env *e, t_point a, t_point b);
void 	case2(t_env *e, t_point a, t_point b);
void 	case3(t_env *e, t_point a, t_point b);

void 	draw_line_mlx(t_env *e, t_point a, t_point b)
{
	int 	dx;
	int 	dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (dx > 0 && dy <= 0)
		case1(e, a, b);
	else if (dx > 0 && dy > 0)
		case2(e, a, b);
	else if (dx < 0 && dy < 0)
		case2(e, b, a);
	else if (dx < 0 && dy >= 0)
		case1(e, b, a);
	else if (dx == 0 && dy != 0)
		case3(e, a, b);
}

void 	case1(t_env *e, t_point a, t_point b)
{
	int 	y;
	int 	x;
	int 	dx;
	int 	dy;

	x = a.x;
	dx = b.x - a.x;
	dy = b.y - a.y;
	while (x < b.x)
	{
		y = ((dy / (double)dx) * (x - a.x)) + a.y;
		img_pixel_put(e, x, y, 0xeeeeee);

		x++;
	}
}

void 	case2(t_env *e, t_point a, t_point b)
{
	int 	y;
	int 	x;
	int 	dx;
	int 	dy;

	x = a.x;
	dx = b.x - a.x;
	dy = b.y - a.y;
	while (x < b.x)
	{
		y = ((dy / (double)dx) * (x - a.x)) + a.y;
		img_pixel_put(e, x, y, 0xeeeeee);
		x++;
	}
}

void 	case3(t_env *e, t_point a, t_point b)
{
	int 	y;

	(void)b.x;
	if (a.y < b.y)
		y = a.y;
	else
	{
		y = b.y;
		b.y = a.y;
	}
	while (y < b.y)
	{
		img_pixel_put(e, a.x, y, 0xeeeeee);
		y++;
	}
}
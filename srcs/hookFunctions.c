/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookFunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 12:47:30 by gmp               #+#    #+#             */
/*   Updated: 2015/02/27 10:46:34 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int 	key_hook(int keycode, t_env *e)
{
	if (ft_isprint(keycode) == 1)
		ft_putnbr(keycode);
	else
		ft_putnbr(keycode);
	ft_putchar('\n');
	if (keyMap(keycode) != -1)
		e->tab[keyMap(keycode)]();
	return (0);
}

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

void 	drawGradient(t_env *e)
{
	int x = 0;
	int y = 0;
	int color = 0xFF0000;
	int r = 0xFF;
	int g = 0x00;
	int b = 0x42;
	while (y < HEIGTH){
		while (x < WIDTH){
			img_pixel_put(e, x, y, color);
			x++;
		}
		if (y % 2 == 0){
			if (r < 0xFF)
				r++;
			if (g < 0xFF)
				g++;
			if (b < 0xFF)
				b++;
		}
		color = (b) + (g << 8) + (r << 16);
		x = 0;
		y++;
	}
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

void 	draw_line_mlx(t_env *e, t_point a, t_point b)
{
	int		x;
	int		y;

	(void)a.z;
	(void)b.z;
	int line_length = sqrt((b.x-a.x)*(b.x-a.x)-(b.y-a.y)*(b.y-a.y));
	//int distance_length = abs(b.z-a.z);
	double step;

	int color_min;
	int color_max;

	if(a.z==b.z)
	{
		if(a.z==0)
		{
			color_min = 0xff0000;
			color_max = 0xff0000;
		}
		if(a.z==10)
		{
			color_min = 0xffffff;
			color_max = 0xffffff;
		}
	}
	else
	{
		if(a.z==0)
			color_min = 0xff0000;
		if(a.z==10)
			color_min = 0xffffff;

		if(b.z==0)
			color_max = 0xff0000;
		if(b.z==10)
			color_max = 0xffffff;
	}

	int color_current = color_min;

	if (a.x == b.x && a.y == b.y)
		return ;
	else if (abs(b.x - a.x) >= abs(b.y - a.y))
	{
		if (a.x > b.x)
			swap_pos(&a.x, &a.y, &b.x, &b.y);
		x = a.x;
		while (x <= b.x)
		{
			if(b.x-a.x == 0)
				return ;
			y = a.y + ((b.y - a.y) * (x - a.x)) / (b.x - a.x);
			
			int distance_current = sqrt((x-a.x)*(x-a.x)-(y-a.y)*(y-a.y));
			step = distance_current/(double)line_length;
			
			color_current = color_min*step+color_max*(1-step);

			if (img_pixel_put(e, x, y, color_current) == -42)
				return ;
			x++;
		}
	}
	else
	{
		if (a.y > b.y)
			swap_pos(&a.x, &a.y, &b.x, &b.y);
		y = a.y;
		while (y <= b.y)
		{
			if(b.y-a.y == 0)
				return;
			x = a.x + ((b.x - a.x) * (y - a.y)) / (b.y - a.y);
			// img_pixel_put(e, x, y, 0xff0000) == -42

			int distance_current = sqrt((x-a.x)*(x-a.x)-(y-a.y)*(y-a.y));
			step = distance_current/(double)line_length;
			
			color_current = color_min*step+color_max*(1-step);

			if (img_pixel_put(e, x, y, color_current) == -42)
				return ;
			y++;
		}
	}
}

void 	draw_circle(t_env *e, int origin_x, int origin_y, int ray)
{
	int x;
	int y;
	int alpha;

	alpha = 0;
	while (alpha < 180){
		x = origin_x + (ray * cos(alpha));
		y = origin_y + (ray * sin(alpha));
		img_pixel_put(e, x, y, 0xff0000);
		alpha++;
	}
}

void 	drawIsometric(t_env *e)
{

	int 	y;
	int 	x;
	int 	scale_y;
	int 	scale_x;
	int 	width;
	int 	heigth;
	double 	x_i_1;
	double 	y_i_1;
	double 	x_i_2;
	double 	y_i_2;
	double 	cte;
	t_point a;
	t_point b;

	x = 0;
	y = 0;
	cte = e->cte;
	scale_x = e->scale;
	scale_y = e->scale;
	heigth = e->map_heigth;
	while (y < heigth - 1){
		width = e->map[y][0];
		while (x < width - 1)
		{

			x_i_1 = ((x) * cte) - (cte * (y + 1));
			y_i_1 = -(e->map[y + 1][x + 1]) + (((cte / 2) * x) + ((cte/2) * (y + 1)));
			x_i_2 = (x * cte) - (cte * y);
			y_i_2 = -(e->map[y][x + 1]) + (((cte / 2) * x) + ((cte/2) * y));
			a.x = (x_i_1 * scale_x) + e->origin_x;
			a.y = (y_i_1 * scale_y) + e->origin_y;
			a.z = e->map[y + 1][x + 1];
			b.x = (x_i_2 * scale_x) + e->origin_x;
			b.y = (y_i_2 * scale_y) + e->origin_y;
			b.z = e->map[y][x + 1];
			draw_line_mlx(e, a, b);

			x_i_1 = ((x) * cte) - (cte * (y + 1));
			y_i_1 = -(e->map[y + 1][x + 1]) + (((cte / 2) * x) + ((cte/2) * (y + 1)));
			x_i_2 = ((x + 1) * cte) - (cte * (y + 1));
			y_i_2 = -(e->map[y + 1][x + 2]) + (((cte / 2) * (x + 1)) + ((cte/2) * (y + 1)));
			a.x = (x_i_1 * scale_x) + e->origin_x;
			a.y = (y_i_1 * scale_y) + e->origin_y;
			a.z = e->map[y + 1][x + 1];
			b.x = (x_i_2 * scale_x) + e->origin_x;
			b.y = (y_i_2 * scale_y) + e->origin_y;
			b.z = e->map[y + 1][x + 2];
			draw_line_mlx(e, a, b);

			x_i_1 = ((x + 1) * cte) - (cte * y);
			y_i_1 = -(e->map[y][x + 2]) + (((cte / 2) * (x + 1)) + ((cte/2) * y));
			x_i_2 = ((x + 1) * cte) - (cte * (y + 1));
			y_i_2 = -(e->map[y + 1][x + 2]) + (((cte / 2) * (x + 1)) + ((cte/2) * (y + 1)));
			a.x = (x_i_1 * scale_x) + e->origin_x;
			a.y = (y_i_1 * scale_y) + e->origin_y;
			a.z = e->map[y + 1][x + 2];
			b.x = (x_i_2 * scale_x) + e->origin_x;
			b.y = (y_i_2 * scale_y) + e->origin_y;
			b.z = e->map[y][x + 2];
			draw_line_mlx(e, a, b);

			x_i_2 = ((x + 1) * cte) - (cte * y);
			y_i_2 = -(e->map[y][x + 2]) + (((cte / 2) * (x + 1)) + ((cte/2) * y));
			x_i_1 = ((x + 1) * cte) - (cte * (y + 1));
			y_i_1 = -(e->map[y + 1][x + 2]) + (((cte / 2) * (x + 1)) + ((cte/2) * (y + 1)));
			a.x = (x_i_1 * scale_x) + e->origin_x;
			a.y = (y_i_1 * scale_y) + e->origin_y;
			a.z = e->map[y + 1][x + 2];
			b.x = (x_i_2 * scale_x) + e->origin_x;
			b.y = (y_i_2 * scale_y) + e->origin_y;
			b.z = e->map[y][x + 2];

			draw_line_mlx(e, a, b);

			x_i_1 = x * cte - (cte * y);
			y_i_1 = -(e->map[y][x + 1]) + (((cte / 2) * x) + ((cte/2) * y));
			x_i_2 = (x + 1) * cte - cte * y;
			y_i_2 = -(e->map[y][x + 2]) + (((cte / 2) * (x + 1)) + ((cte/2) * y));
			a.x = (x_i_1 * scale_x) + e->origin_x;
			a.y = (y_i_1 * scale_y) + e->origin_y;
			a.z = e->map[y][x + 1];
			b.x = (x_i_2 * scale_x) + e->origin_x;
			b.y = (y_i_2 * scale_y) + e->origin_y;
			b.z = e->map[y][x + 2];
			draw_line_mlx(e, a, b);
			x++;
		}
		x = 0;
		y++;
	}

}

void 	drawParallele(t_env *e)
{	
	int 	y;
	int 	x;
	int 	scale_y;
	int 	scale_x;
	int 	width;
	int 	heigth;
	double 	x_i_1;
	double 	y_i_1;
	double 	x_i_2;
	double 	y_i_2;
	double 	cte;
	t_point a;
	t_point b;

	x = 0;
	y = 0;
	cte = e->cte / 6;
	scale_x = e->scale;
	scale_y = e->scale;
	heigth = e->map_heigth;
	// width = e->map[y][0];
	while (y < heigth - 1){
		width = e->map[y][0];
		while (x < width - 1)
		{
			x_i_1 = x + (cte * e->map[y][x + 1]);
			y_i_1 = y + ((cte/2) * (e->map[y][x + 1]));
			x_i_2 = (x + 1) + (cte * e->map[y][x + 2]);
			y_i_2 = (y) + ((cte/2) * (e->map[y][x + 2]));
			a.x = (x_i_1 * scale_x) + e->origin_x;
			a.y = (y_i_1 * scale_y) + e->origin_y;
			a.z = e->map[y][x + 1];
			b.x = (x_i_2 * scale_x) + e->origin_x;
			b.y = (y_i_2 * scale_y) + e->origin_y;
			b.z = e->map[y][x + 2];
			draw_line_mlx(e, a, b);

			x_i_1 = x + (cte * e->map[y][x + 1]);
			y_i_1 = y + ((cte/2) * (e->map[y][x + 1]));
			x_i_2 = (x) + (cte * e->map[y + 1][x + 1]);
			y_i_2 = (y + 1) + ((cte/2) * (e->map[y + 1][x + 1]));
			a.x = (x_i_1 * scale_x) + e->origin_x;
			a.y = (y_i_1 * scale_y) + e->origin_y;
			a.z = e->map[y][x + 1];
			b.x = (x_i_2 * scale_x) + e->origin_x;
			b.y = (y_i_2 * scale_y) + e->origin_y;
			b.z = e->map[y + 1][x + 1];
			draw_line_mlx(e, a, b);

			x_i_1 = x + (cte * e->map[y + 1][x + 1]);
			y_i_1 = y + 1 + ((cte/2) * (e->map[y + 1][x + 1]));
			x_i_2 = (x + 1) + (cte * e->map[y + 1][x + 2]);
			y_i_2 = (y + 1) + ((cte/2) * (e->map[y + 1][x + 2]));
			a.x = (x_i_1 * scale_x) + e->origin_x;
			a.y = (y_i_1 * scale_y) + e->origin_y;
			a.z = e->map[y + 1][x + 1];
			b.x = (x_i_2 * scale_x) + e->origin_x;
			b.y = (y_i_2 * scale_y) + e->origin_y;
			b.z = e->map[y + 1][x + 2];
			draw_line_mlx(e, a, b);


			x_i_1 = (x + 1) + (cte * e->map[y][x + 2]);
			y_i_1 = (y) + ((cte/2) * (e->map[y][x + 2]));
			x_i_2 = (x + 1) + (cte * e->map[y + 1][x + 2]);
			y_i_2 = (y + 1) + ((cte/2) * (e->map[y + 1][x + 2]));
			a.x = (x_i_1 * scale_x) + e->origin_x;
			a.y = (y_i_1 * scale_y) + e->origin_y;
			a.z = e->map[y][x + 2];
			b.x = (x_i_2 * scale_x) + e->origin_x;
			b.y = (y_i_2 * scale_y) + e->origin_y;
			b.z = e->map[y + 1][x + 2];
			draw_line_mlx(e, a, b);
			x++;
		}
		x = 0;
		y++;
	}
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

int 	expose_hook(t_env *e)
{
	clearImg(e);
	if (e->perspective == 1)
		drawIsometric(e);
	else
		drawParallele(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookFunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 12:47:30 by gmp               #+#    #+#             */
/*   Updated: 2015/02/22 16:57:02 by gmp              ###   ########.fr       */
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
	// if (e->data[i] != 0 && e->data[i + 1] != 0 && e->data[i + 2] != 0)
		// return -42;
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

void 	draw_line_mlx(t_env *e, int x1, int y1, int x2, int y2, int color)
{
	int		x;
	int		y;

	if (x1 == x2 && y1 == y2)
		return ;
	else if (fabs(x2 - x1) >= fabs(y2 - y1))
	{
		if (x1 > x2)
			swap_pos(&x1, &y1, &x2, &y2);
		x = x1;
		while (x <= x2)
		{
			if(x2-x1 == 0)
				return ;
			y = y1 + ((y2 - y1) * (x - x1)) / (x2 - x1);
			
			if (img_pixel_put(e, x, y, color) == -42)
				return ;
			x++;
		}
	}
	else
	{
		if (y1 > y2)
			swap_pos(&x1, &y1, &x2, &y2);
		y = y1;
		while (y <= y2)
		{
			if(y2-y1 == 0)
				return;
			x = x1 + ((x2 - x1) * (y - y1)) / (y2 - y1);
			// img_pixel_put(e, x, y, color) == -42
			if (img_pixel_put(e, x, y, color) == -42)
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
			x_i_1 = x * cte - (cte * y);
			y_i_1 = -(e->map[y][x + 1]) + (((cte / 2) * x) + ((cte/2) * y));
			x_i_2 = (x + 1) * cte - cte * y;
			y_i_2 = -(e->map[y][x + 2]) + (((cte / 2) * (x + 1)) + ((cte/2) * y));
			draw_line_mlx(e, (x_i_1 * scale_x) + e->origin_x, (y_i_1 * scale_y) + e->origin_y, (x_i_2 * scale_x) + e->origin_x, (y_i_2 * scale_y) + e->origin_y, 0xff0000);

			x_i_1 = ((x) * cte) - (cte * (y + 1));
			y_i_1 = -(e->map[y + 1][x + 1]) + (((cte / 2) * x) + ((cte/2) * (y + 1)));
			x_i_2 = (x * cte) - (cte * y);
			y_i_2 = -(e->map[y][x + 1]) + (((cte / 2) * x) + ((cte/2) * y));
			draw_line_mlx(e, (x_i_1 * scale_x) + e->origin_x, (y_i_1 * scale_y) + e->origin_y, (x_i_2 * scale_x) + e->origin_x, (y_i_2 * scale_y) + e->origin_y, 0xff0000);

			x_i_1 = ((x) * cte) - (cte * (y + 1));
			y_i_1 = -(e->map[y + 1][x + 1]) + (((cte / 2) * x) + ((cte/2) * (y + 1)));
			x_i_2 = ((x + 1) * cte) - (cte * (y + 1));
			y_i_2 = -(e->map[y + 1][x + 2]) + (((cte / 2) * (x + 1)) + ((cte/2) * (y + 1)));
			draw_line_mlx(e, (x_i_1 * scale_x) + e->origin_x, (y_i_1 * scale_y) + e->origin_y, (x_i_2 * scale_x) + e->origin_x, (y_i_2 * scale_y) + e->origin_y, 0xff0000);

			x_i_1 = ((x + 1) * cte) - (cte * (y + 1));
			y_i_1 = -(e->map[y + 1][x + 2]) + (((cte / 2) * (x + 1)) + ((cte/2) * (y + 1)));
			x_i_2 = ((x + 1) * cte) - (cte * y);
			y_i_2 = -(e->map[y][x + 2]) + (((cte / 2) * (x + 1)) + ((cte/2) * y));
			draw_line_mlx(e, (x_i_1 * scale_x) + e->origin_x, (y_i_1 * scale_y) + e->origin_y, (x_i_2 * scale_x) + e->origin_x, (y_i_2 * scale_y) + e->origin_y, 0xff0000);

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

	x = 0;
	y = 0;
	cte = e->cte;
	scale_x = e->scale;
	scale_y = e->scale;
	heigth = e->map_heigth;
	// width = e->map[y][0];
	while (y < heigth - 1){
		width = e->map[y][0];
		while (x < width)
		{
			x_i_1 = x + (cte * e->map[y][x + 1]);
			y_i_1 = y + ((cte/2) * (e->map[y][x + 1]));
			x_i_2 = (x + 1) + (cte * e->map[y][x + 2]);
			y_i_2 = (y) + ((cte/2) * (e->map[y][x + 2]));
			draw_line_mlx(e, x_i_1 * scale_x + e->origin_x, y_i_1 * scale_y + e->origin_y, x_i_2 * scale_x + e->origin_x, y_i_2 * scale_y + e->origin_y, 0xff0000);
			x_i_2 = (x) + (cte * e->map[y + 1][x + 1]);
			y_i_2 = (y + 1) + ((cte/2) * (e->map[y + 1][x + 1]));
			draw_line_mlx(e, x_i_1* scale_x + e->origin_x, y_i_1 * scale_y + e->origin_y, x_i_2 * scale_x + e->origin_x, y_i_2 * scale_y + e->origin_y, 0xff0000);

			x_i_1 = x + (cte * e->map[y + 1][x + 1]);
			y_i_1 = y + 1 + ((cte/2) * (e->map[y + 1][x + 1]));
			x_i_2 = (x + 1) + (cte * e->map[y + 1][x + 2]);
			y_i_2 = (y + 1) + ((cte/2) * (e->map[y + 1][x + 2]));
			draw_line_mlx(e, x_i_1 * scale_x + e->origin_x, y_i_1 * scale_y + e->origin_y, x_i_2 * scale_x + e->origin_x, y_i_2 * scale_y + e->origin_y, 0xff0000);

			// x_i_1 = x + 1 + (cte * e->map[y + 1][x + 2]);
			// y_i_1 = y + 1 + ((cte/2) * (e->map[y + 1][x + 2]));
			// x_i_2 = (x + 1) + (cte * e->map[y][x + 2]);
			// y_i_2 = (y) + ((cte/2) * (e->map[y][x + 2]));
			// draw_line_mlx(e, x_i_1 * scale_x, y_i_1 * scale_y, x_i_2 * scale_x, y_i_2 * scale_y, 0xff0000);


			// x_i_1 = x + (cte * e->map[y + 1][x + 1]);
			// y_i_1 = y + 1 + ((cte/2) * (e->map[y + 1][x + 1]));
			// x_i_2 = (x + 1) + (cte * e->map[y + 1][x + 2]);
			// y_i_2 = (y + 1) + ((cte/2) * (e->map[y + 1][x + 2]));
			// draw_line_mlx(e, x_i_1 * scale_x, y_i_1 * scale_y, x_i_2 * scale_x, y_i_2 * scale_y, 0xff0000);

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
	// drawGradient(e);
	clearImg(e);
	// drawParallele(e);
	if (e->perspective == 1)
		drawIsometric(e);
	else
		drawParallele(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

// int 	loop_hook(t_env *e)
// {
// 	expose_hook(e);
// 	return (0);
// }

void 	key_arrow_up(void)
{
	t_env	*e;

	e = getEnv();
	e->origin_y -= 10;
	expose_hook(e);
	ft_putstr("UP\n");
}

void 	key_arrow_down(void)
{
	t_env	*e;

	e = getEnv();
	e->origin_y += 10;
	expose_hook(e);
	ft_putstr("DOWN\n");
}

void 	key_arrow_right(void)
{
	t_env	*e;

	e = getEnv();
	e->origin_x += 10;
	expose_hook(e);
	ft_putstr("RIGHT\n");	
}

void 	key_arrow_left(void)
{
	t_env	*e;

	e = getEnv();
	e->origin_x -= 10;
	expose_hook(e);
	ft_putstr("LEFT\n");	
}

void 	key_p(void)
{
	t_env	*e;

	e = getEnv();
	e->scale += 10;
	expose_hook(e);
	ft_putstr("P\n");	
}

void 	key_m(void)
{
	t_env	*e;

	e = getEnv();
	if (e->scale == 0)
		return ;
	e->scale -= 10;
	expose_hook(e);
	ft_putstr("P\n");	
}

void 	key_1(void)
{
	t_env	*e;

	e = getEnv();
	e->perspective = 1;
	expose_hook(e);
	ft_putstr("P\n");	
}

void 	key_2(void)
{
	t_env	*e;

	e = getEnv();
	e->perspective = 2;
	expose_hook(e);
	ft_putstr("P\n");	
}
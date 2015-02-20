/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookFunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 12:47:30 by gmp               #+#    #+#             */
/*   Updated: 2015/02/20 18:45:30 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	key_hook(int keycode, t_env *e)
{
	if (ft_isprint(keycode) == 1)
		ft_putchar(keycode);
	else
		ft_putnbr(keycode);
	ft_putchar('\n');
	if (keyMap(keycode) != -1)
		e->tab[keyMap(keycode)]();
	return (0);
}

void	img_pixel_put(t_env *e, int x, int y, int color)
{
	unsigned int	new_color;
	int	i;

	new_color = mlx_get_color_value(e->mlx, color);
	i = x * 4 + y * e->size_line;
	e->data[i] = (new_color & 0xFF);
	e->data[i + 1] = (new_color & 0xFF00) >> 8;
	e->data[i + 2] = (new_color & 0xFF0000) >> 16;
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
			y = y1 + ((y2 - y1) * (x - x1)) / (x2 - x1);
			img_pixel_put(e, x, y, color);
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
			x = x1 + ((x2 - x1) * (y - y1)) / (y2 - y1);
			img_pixel_put(e, x, y, color);
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

int 	expose_hook(t_env *e)
{
	drawGradient(e);
	// draw_circle(e, 200, 200, 100);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int 	keyMap(int keycode){
	if (65307 == keycode)
		return 0;
	return -1;
}
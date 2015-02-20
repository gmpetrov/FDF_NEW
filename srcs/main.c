/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 09:53:56 by gmp               #+#    #+#             */
/*   Updated: 2015/02/20 12:46:01 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_escape(void)
{
	ft_putstr("escape\n");
	exit(0);
}

void	draw(void *mlx, void *win)
{
	int x = 0;
	int y = 0;
	int color = 0xFF0000;
	int r = 0xFF;
	int g = 0x00;
	int b = 0x42;
	while (y < 400){
		while (x < 400){
			mlx_pixel_put(mlx, win, x, y, color);
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

int 	expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}

int 	keyMap(int keycode){
	if (65307 == keycode)
		return 0;
	return -1;
}

int 	key_hook(int keycode, t_env *e)
{
	(void)e;
	ft_putnbr(keycode);
	ft_putchar('\n');
	e->tab[keyMap(keycode)]();
	return (0);
}


void	initPtrTab(t_env *e)
{
	e->tab[0] = &key_escape;
}

t_env	*getEnv()
{
	static t_env	*e = NULL;
	if (e == NULL){
		e = (t_env *)malloc(sizeof(*e));
		initPtrTab(e);
	}
	return e;
}

int     main(void){
	t_env		*e = getEnv();

	// e->tab[0]();
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 400, 400, "YOLO BIG PIG");
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 12:53:44 by gmp               #+#    #+#             */
/*   Updated: 2015/03/04 17:03:04 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_usage(void)
{
	ft_putstr("usage: ./fdf [data_file]\n");
	exit(0);
}

t_env	*get_env(void)
{
	static t_env	*e = NULL;

	if (e == NULL)
	{
		e = (t_env *)malloc(sizeof(t_env));
		if ((e->mlx = mlx_init()) == NULL)
			ft_usage();
		e->win = mlx_new_window(e->mlx, WIDTH, HEIGTH, "FDF");
		e->img = mlx_new_image(e->mlx, WIDTH, HEIGTH);
		e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
		e->scale = 5;
		e->origin_x = 250;
		e->origin_y = 130;
		e->perspective = 1;
		e->cte = 10;
		e->color = 0xFF0000;
		init_ptr_tab(e);
	}
	return (e);
}

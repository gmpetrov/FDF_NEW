/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 12:53:44 by gmp               #+#    #+#             */
/*   Updated: 2015/02/20 17:53:23 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initPtrTab(t_env *e)
{
	e->tab[0] = &key_escape;
}

t_env	*getEnv()
{
	static t_env	*e = NULL;
	if (e == NULL){
		e = (t_env *)malloc(sizeof(t_env));
		e->mlx = mlx_init();
		e->win = mlx_new_window(e->mlx, WIDTH, HEIGTH, "FDF");
		e->img = mlx_new_image(e->mlx, WIDTH, HEIGTH);
		e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
		initPtrTab(e);
	}
	return e;
}
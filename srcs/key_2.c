/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 09:15:42 by gmp               #+#    #+#             */
/*   Updated: 2015/02/27 09:15:51 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
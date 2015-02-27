/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 09:14:50 by gmp               #+#    #+#             */
/*   Updated: 2015/02/27 12:30:57 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 	key_p(void)
{
	t_env	*e;

	e = getEnv();
	e->scale += 1;
	expose_hook(e);
	ft_putstr("P\n");
}

void 	key_m(void)
{
	t_env	*e;

	e = getEnv();
	if (e->scale == 0)
		return ;
	e->scale -= 1;
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
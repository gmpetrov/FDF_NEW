/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 09:15:42 by gmp               #+#    #+#             */
/*   Updated: 2015/03/04 16:30:46 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_arrow_up(void)
{
	t_env	*e;

	e = get_env();
	e->origin_y -= 10;
	expose_hook(e);
	ft_putstr("UP\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 15:35:07 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/04 16:29:28 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_p(void)
{
	t_env	*e;

	e = get_env();
	e->scale += 1;
	expose_hook(e);
	ft_putstr("P\n");
}
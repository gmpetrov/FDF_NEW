/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:54:59 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/04 16:13:25 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_env *e)
{
	if (ft_isprint(keycode) == 1)
		ft_putnbr(keycode);
	else
		ft_putnbr(keycode);
	ft_putchar('\n');
	if (key_map(keycode) != -1)
		e->tab[key_map(keycode)]();
	return (0);
}

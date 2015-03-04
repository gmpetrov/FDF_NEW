/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ptr_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:46:44 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/04 13:47:08 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_ptr_tab(t_env *e)
{
	e->tab[0] = &key_escape;
	e->tab[1] = &key_arrow_up;
	e->tab[2] = &key_arrow_down;
	e->tab[3] = &key_arrow_right;
	e->tab[4] = &key_arrow_left;
	e->tab[5] = &key_p;
	e->tab[6] = &key_m;
	e->tab[7] = &key_1;
	e->tab[8] = &key_2;
}

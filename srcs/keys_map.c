/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:47:34 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/04 16:31:47 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_map(int keycode)
{
	if (65307 == keycode)
		return (0);
	else if (65362 == keycode)
		return (1);
	else if (65364 == keycode)
		return (2);
	else if (65363 == keycode)
		return (3);
	else if (65361 == keycode)
		return (4);
	else if (112 == keycode)
		return (5);
	else if (59 == keycode)
		return (6);
	else if (49 == keycode)
		return (7);
	else if (50 == keycode)
		return (8);
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_nb_only.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 17:38:09 by gpetrov           #+#    #+#             */
/*   Updated: 2015/03/04 19:06:23 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_str_nb_only(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (-1);
	while (i < ft_strlen(str))
	{
		if (!ft_isdigit(str[i]) && str[i] != '\n' && str[i] != '\t' \
			&& str[i] != ' ')
			return (-1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 09:53:56 by gmp               #+#    #+#             */
/*   Updated: 2015/03/04 17:07:01 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av, char **env)
{
	t_env		*e;

	if (!*env)
		ft_usage();
	e = get_env();
	e->map = ft_get_data(ac, av);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
	return (0);
}

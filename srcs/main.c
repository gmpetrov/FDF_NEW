/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 09:53:56 by gmp               #+#    #+#             */
/*   Updated: 2015/02/21 18:24:34 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_escape(void)
{
	ft_putstr("escape\n");
	exit(0);
}

int     main(int ac, char **av){
	t_env		*e = getEnv();

	e->map = ft_get_data(ac, av);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	// mlx_loop_hook(e->win, loop_hook, e);
	mlx_loop(e->mlx);
    return (0);
}

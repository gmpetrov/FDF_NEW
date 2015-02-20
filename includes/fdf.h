/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 10:28:21 by gmp               #+#    #+#             */
/*   Updated: 2015/02/20 15:43:10 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 400
# define HEIGTH 400

# include "libft.h"
# include <mlx.h>


# include <stdio.h>

/* STRUCTURES */

typedef struct 		s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int 	bpp;
	int 	size_line;
	int 	endian;
	void (*tab[42])();
}					t_env;

/* PROTOTYPES */

int 	expose_hook(t_env *e);
int 	key_hook(int keycode, t_env *e);
void	initPtrTab(t_env *e);
t_env	*getEnv();
int 	keyMap(int keycode);
void 	img_pixel_put(t_env *e, int x, int y, int color);

void	drawGradient(t_env *e);

/* KEY FUNCTION */

void	key_escape(void);

/* END PROTOTYPES */

#endif
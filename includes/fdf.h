/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 10:28:21 by gmp               #+#    #+#             */
/*   Updated: 2015/02/21 19:33:16 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 200
# define HEIGTH 200

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

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
	int 	**map;
	int 	scale;
	int 	map_heigth;
	int 	origin_x;
	int 	origin_y;
	int 	perspective;
	double 	cte;
	void (*tab[42])();
}					t_env;

/* PROTOTYPES */

int 	expose_hook(t_env *e);
int 	key_hook(int keycode, t_env *e);
// int 	loop_hook(t_env *e);
void	initPtrTab(t_env *e);
t_env	*getEnv();
int 	keyMap(int keycode);
int 	img_pixel_put(t_env *e, int x, int y, int color);
void 	draw_line_mlx(t_env *e, int x1, int y1, int x2, int y2, int color);

void 	drawParallele(t_env *e);
void 	drawIsometric(t_env *e);

void	drawGradient(t_env *e);

/* PARSING */

int		**ft_get_data(int argc, char **argv);
int		ft_tablen(char **tab);
int		ft_data_size(char *file);
int		*ft_put_data(char *str);

/* KEY FUNCTION */

void	key_escape(void);
void 	key_arrow_up(void);
void 	key_arrow_down(void);
void 	key_arrow_right(void);
void 	key_arrow_left(void);
void 	key_p(void);
void 	key_m(void);
void 	key_1(void);
void 	key_2(void);

/* END PROTOTYPES */

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 10:28:21 by gmp               #+#    #+#             */
/*   Updated: 2015/03/04 18:36:27 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 2000
# define HEIGTH 1000

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	int				**map;
	int				scale;
	int				map_heigth;
	int				origin_x;
	int				origin_y;
	int				perspective;
	double			cte;
	double			x_i_1;
	double			y_i_1;
	double			x_i_2;
	double			y_i_2;
	int				color;
	void			(*tab[42])();
}					t_env;

int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
void				clear_img(t_env *e);
void				init_ptr_tab(t_env *e);
t_env				*get_env();
int					key_map(int keycode);
int					img_pixel_put(t_env *e, int x, int y, int color);
void				draw_line_mlx(t_env *e, t_point a, t_point b);
void				draw_parallele(t_env *e);
void				draw_isometric(t_env *e);
void				draw_gradient(t_env *e);
void				ft_usage(void);
int					is_str_nb_only(char *str);

int					**ft_get_data(int argc, char **argv);

void				key_escape(void);
void				key_arrow_up(void);
void				key_arrow_down(void);
void				key_arrow_right(void);
void				key_arrow_left(void);
void				key_p(void);
void				key_m(void);
void				key_1(void);
void				key_2(void);

#endif

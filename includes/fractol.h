/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:29:05 by huweber           #+#    #+#             */
/*   Updated: 2017/02/27 17:19:56 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define EXIT 53
# define MINUS 78
# define PLUS 69
# define RESET 15
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define COLOR 8
# define PAUSE 35
# define KEYPRESS_MASK (1L<<0)
# define MOUSEMOV_MASK (1L<<6)
# define MOTION_EVENT 6
# define WHEEL_UP 7
# define WHEEL_DOWN 5

typedef struct			s_env
{
	int					winx;
	int					winy;
	void				*mlx;
	void				*win;
	void				*img;
	char				*addr;
	long double			xmarg;
	long double			ymarg;
	int					sline;
	int					bpp;
	int					ed;
	intmax_t			x;
	intmax_t			y;
	int					c;
	int					auto_c;
	long double			c_ip;
	long double			c_rp;
	intmax_t			zoom;
	int					mx;
	int					my;
	int					mblock;
	int					i_max;
	int					type;
	struct s_fractal	*f;
}						t_env;

typedef struct			s_fractal
{
	long double			z_r;
	long double			z_i;
	long double			c_r;
	long double			c_i;
	long double			zr_tmp;
}						t_fractal;

void					init_fractal(t_env *e);

/*
**		FILE MAIN.C
*/

int						real_ima(t_env *e, t_fractal *f, int i);
void					set_default(t_env *e);

/*
**		FILE DRAW.C
*/

void					put_pixel(t_env *e, int x, int y, int c);
unsigned int			color_depth(t_env *e, int i);
void					draw_mandel(t_env *e, t_fractal *f);
void					draw_julia(t_env *e, t_fractal *f);
void					draw_ship(t_env *e, t_fractal *f);

/*
**		FILE UTILS.C
*/

int						get_type(char *av);
void					put_env(t_env *e);
void					free_env(t_env *e);
void					ft_print_err(char *err);
void					print_usage(int type);

/*
**		FILE HOOK.C
*/

int						keyrelease(int keycode, t_env *e);
int						mouse_clic(int button, int x, int y, t_env *e);
int						mousemove(int x, int y, t_env *e);

#endif

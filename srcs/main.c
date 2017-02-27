/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:36:45 by huweber           #+#    #+#             */
/*   Updated: 2017/02/27 17:47:45 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					real_ima(t_env *e, t_fractal *f, int i)
{
	while (++i < e->i_max)
	{
		f->zr_tmp = f->z_r;
		f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		if (e->type == 3)
			f->z_i = 2 * fabsl(f->z_i * f->zr_tmp) + f->c_i;
		else
			f->z_i = 2 * f->z_i * f->zr_tmp + f->c_i;
		if (f->z_r * f->z_r + f->z_i * f->z_i >= 4)
			break ;
	}
	return (i);
}

void				set_default(t_env *e)
{
	e->i_max = (e->type == 2) ? 150 : 50;
	e->auto_c = 0;
	e->mblock = 0;
	e->winx = 1200;
	e->winy = 900;
	e->xmarg = -2.8;
	e->ymarg = -1.5;
	e->mx = 0;
	e->my = 0;
	e->c_ip = 0;
	e->c_rp = 0;
	e->x = 0;
	e->y = 0;
	e->c = 250;
	e->zoom = 250;
}

void				init_fractal(t_env *e)
{
	e->img = mlx_new_image(e->mlx, e->winx, e->winy);
	e->addr = mlx_get_data_addr(e->img, &(e->bpp), &(e->sline), &(e->ed));
	if (!e->f)
		e->f = (t_fractal *)malloc(sizeof(t_fractal));
	if (!e->f)
		ft_print_err("MALLOC");
	if (e->type == 1)
		draw_mandel(e, e->f);
	else if (e->type == 2)
		draw_julia(e, e->f);
	else if (e->type == 3)
		draw_ship(e, e->f);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	put_env(e);
}

int					expose_hook(t_env *e)
{
	init_fractal(e);
	return (0);
}

int					main(int ac, char **av)
{
	t_env			*e;

	if (ac != 2)
		ft_print_err("USAGE");
	e = (t_env *)malloc(sizeof(t_env));
	if (!e)
		ft_print_err("ALLOC");
	e->mlx = mlx_init();
	if ((e->type = get_type(av[1])) == 0)
		ft_print_err("USAGE");
	set_default(e);
	e->win = mlx_new_window(e->mlx, e->winx, e->winy, "fract'ol");
	init_fractal(e);
	print_usage(1);
	mlx_hook(e->win, MOTION_EVENT, MOUSEMOV_MASK, mousemove, e);
	mlx_key_hook(e->win, keyrelease, e);
	mlx_mouse_hook(e->win, mouse_clic, e);
	mlx_loop(e->mlx);
	return (0);
}

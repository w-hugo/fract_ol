/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:04:29 by huweber           #+#    #+#             */
/*   Updated: 2017/02/27 16:30:08 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			put_pixel(t_env *e, int x, int y, int c)
{
	int			i;

	i = (e->sline * y) + (x * 4);
	if (y >= e->winy || i < 0 || i > e->sline * e->winy +
		e->sline * e->winx || x <= 0 || x >= e->winx)
		return ;
	e->addr[i] = c;
	e->addr[++i] = c >> 8;
	e->addr[++i] = c >> 16;
}

unsigned int	color_depth(t_env *e, int i)
{
	if (i == 0)
		i++;
	return (((255 - i * e->c) << 16)
			+ ((255 - i * (e->c * 2)) << 8)
			+ (255 - i * (e->c * 3)));
}

void			draw_ship(t_env *e, t_fractal *f)
{
	intmax_t	x;
	intmax_t	y;
	int			i;

	y = e->y;
	while (++y < e->winy + e->y)
	{
		x = e->x;
		while (++x < e->winx + e->x)
		{
			f->c_r = (long double)x / e->zoom + e->xmarg;
			f->c_i = (long double)y / e->zoom + e->ymarg;
			f->z_r = 0 + e->c_rp;
			f->z_i = 0 + e->c_ip;
			i = -1;
			i = real_ima(e, f, i);
			if (i != e->i_max)
				put_pixel(e, x - e->x, y - e->y, color_depth(e, i));
		}
	}
}

void			draw_julia(t_env *e, t_fractal *f)
{
	intmax_t	x;
	intmax_t	y;
	int			i;

	y = e->y;
	while (++y < e->winy + e->y)
	{
		x = e->x;
		while (++x < e->winx + e->x)
		{
			f->z_r = (long double)x / e->zoom + e->xmarg;
			f->z_i = (long double)y / e->zoom + e->ymarg;
			i = -1;
			f->c_r = e->c_ip;
			f->c_i = e->c_rp;
			i = real_ima(e, f, i);
			if (i != e->i_max)
				put_pixel(e, x - e->x, y - e->y, color_depth(e, i));
		}
	}
}

void			draw_mandel(t_env *e, t_fractal *f)
{
	intmax_t	x;
	intmax_t	y;
	int			i;

	y = e->y;
	while (++y < e->winy + e->y)
	{
		x = e->x;
		while (++x < e->winx + e->x)
		{
			f->c_r = (long double)x / e->zoom + e->xmarg;
			f->c_i = (long double)y / e->zoom + e->ymarg;
			f->z_r = 0 + e->c_rp;
			f->z_i = 0 + e->c_ip;
			i = -1;
			i = real_ima(e, f, i);
			if (i != e->i_max)
				put_pixel(e, x - e->x, y - e->y, color_depth(e, i));
		}
	}
}

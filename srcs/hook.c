/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:32:21 by huweber           #+#    #+#             */
/*   Updated: 2017/02/27 17:14:37 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			keyrelease(int keycode, t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	if (keycode == COLOR)
		e->auto_c = (e->auto_c == 0) ? 1 : 0;
	if (keycode == EXIT)
		free_env(e);
	if (keycode == RESET)
		set_default(e);
	if (keycode == PLUS)
		e->i_max += 10;
	if (keycode == MINUS)
		if (e->i_max > 10)
			e->i_max -= 10;
	if (keycode == LEFT)
		e->x += 10;
	if (keycode == RIGHT)
		e->x -= 10;
	if (keycode == UP)
		e->y += 10;
	if (keycode == DOWN)
		e->y -= 10;
	if (keycode == PAUSE)
		e->mblock = (e->mblock == 0) ? 1 : 0;
	init_fractal(e);
	return (0);
}

int			mouse_clic(int button, int x, int y, t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	if (button == 1 || button == 5)
	{
		e->x += x / 6;
		e->y += y / 6;
		e->zoom = e->zoom * 1.2;
		e->y = e->y * 1.2;
		e->x = e->x * 1.2;
		e->i_max += 1;
	}
	if (button == 2 || button == 4)
	{
		e->x -= x / 5;
		e->y -= y / 5;
		e->zoom = e->zoom * 0.8;
		e->y = e->y * 0.8;
		e->x = e->x * 0.8;
		e->i_max -= 1;
	}
	init_fractal(e);
	return (0);
}

int			mousemove(int x, int y, t_env *e)
{
	e->mx = x;
	e->my = y;
	if (e->type == 2 && e->mblock == 0 && x > 0 && y > 0
		&& x < e->winx && y < e->winy)
	{
		e->c_rp = -0.4 + (0.2 / ((long double)x / (long double)e->winx));
		e->c_ip = (0.15 / ((long double)y / (long double)e->winy));
		mlx_destroy_image(e->mlx, e->img);
		if (e->auto_c == 1)
			e->c++;
		init_fractal(e);
		return (0);
	}
	if (e->auto_c == 1)
	{
		e->c++;
		init_fractal(e);
	}
	return (0);
}

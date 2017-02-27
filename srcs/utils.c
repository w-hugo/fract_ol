/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:03:57 by huweber           #+#    #+#             */
/*   Updated: 2017/02/27 17:42:32 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			put_env(t_env *e)
{
	char		*tmp;

	tmp = ft_itoa(e->x);
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFFFF, "X ");
	mlx_string_put(e->mlx, e->win, 70, 10, 0xFFFFFF, tmp);
	free(tmp);
	tmp = ft_itoa(e->y);
	mlx_string_put(e->mlx, e->win, 10, 30, 0xFFFFFF, "Y ");
	mlx_string_put(e->mlx, e->win, 70, 30, 0xFFFFFF, tmp);
	free(tmp);
	tmp = ft_itoa(e->i_max);
	mlx_string_put(e->mlx, e->win, 10, 90, 0xFFFFFF, "DEEP ");
	mlx_string_put(e->mlx, e->win, 70, 90, 0xFFFFFF, tmp);
	free(tmp);
	tmp = ft_itoa(e->mx);
	mlx_string_put(e->mlx, e->win, 10, 50, 0xFFFFFF, "PTR_X ");
	mlx_string_put(e->mlx, e->win, 70, 50, 0xFFFFFF, tmp);
	free(tmp);
	tmp = ft_itoa(e->my);
	mlx_string_put(e->mlx, e->win, 10, 70, 0xFFFFFF, "PTR_Y ");
	mlx_string_put(e->mlx, e->win, 70, 70, 0xFFFFFF, tmp);
	free(tmp);
}

int				get_type(char *av)
{
	if (!(ft_strcmp(av, "mandelbrot")))
		return (1);
	else if (!(ft_strcmp(av, "julia")))
		return (2);
	else if (!(ft_strcmp(av, "ship")))
		return (3);
	return (0);
}

void			print_usage(int type)
{
	if (type == 0)
		ft_putendl("Usage: ./fdf [mandelbrot/julia/ship]");
	else
	{
		ft_putendl("Keys :		WASD					Move Image");
		ft_putendl("		Mouse Wheel/Left-Right Clic		\
Zoom In--Zoom Out");
		ft_putendl("		C					\
Color Change With Pointer Motion");
		ft_putendl("		P					\
Pause Motion Refresh for Julia's Ensemble");
		ft_putendl("		NUMPAD +/-				\
Increase/Decrease Deepness");
	}
}

void			ft_print_err(char *err)
{
	if (!(ft_strcmp(err, "OPEN")))
		ft_putendl_fd("Invalid File.", 2);
	if (!(ft_strcmp(err, "LINE_LEN")))
		ft_putendl_fd("A wrong line len has been found.", 2);
	if (!(ft_strcmp(err, "ALLOC")))
		ft_putendl_fd("Memory allocation failed.", 2);
	if (!(ft_strcmp(err, "USAGE")))
		print_usage(0);
	exit(1);
}

void			free_env(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	free(e->mlx);
	if (e->f)
		free(e->f);
	free(e);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:30:27 by imarakho          #+#    #+#             */
/*   Updated: 2017/02/24 14:07:02 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		hook_func(int x, int y, t_fract *fr)
{
	fr->x = x;
	fr->y = y;
	if (fr->fl == 1 && fr->x <= fr->wsize && fr->x >= 0
		&& fr->y <= fr->wsize && fr->y >= 0)
		ft_strequ(fr->filename, "julia") ? movejulia(fr) : 0;
	return (0);
}

int		key_func(int key, t_fract *fr)
{
	ft_strequ(fr->filename, "julia") ? check_julia(fr, key) : 0;
	ft_strequ(fr->filename, "mandel") ? check_mandel(fr, key) : 0;
	ft_strequ(fr->filename, "burnship") ? check_burnship(fr, key) : 0;
	if (key == 4)
		fr->fl *= -1;
	if (key == 53)
	{
		ft_putstr("Exit program\n");
		exit(1);
	}
	return (0);
}

int		mouse_func(int click, int x, int y, t_fract *fr)
{
	int		a;

	click == 1 ? fr->fl = 1 : 0;
	if (click == 5)
	{
		fr->zx = fr->zx + (fr->zx - x) / 5;
		fr->zy = fr->zy + (fr->zy - y) / 5;
		fr->zoom += fr->zoom / 5;
	}
	if (click == 4)
	{
		fr->zx = fr->zx - (fr->zx - x) / 5;
		fr->zy = fr->zy - (fr->zy - y) / 5;
		fr->zoom -= fr->zoom / 5;
	}
	fr->img = mlx_new_image(fr->mlx, fr->wsize, fr->wsize);
	ft_strequ(fr->filename, "julia") ? ft_julia(fr) : 0;
	ft_strequ(fr->filename, "mandel") ? ft_mandel(fr) : 0;
	ft_strequ(fr->filename, "burnship") ? ft_burnship(fr) : 0;
	a = mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
	mlx_destroy_image(fr->mlx, fr->img);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fract		fr;
	int			a;

	if (argc != 2)
	{
		ft_putstr("mandel\njulia\nburnship\nfish\ntrees\n");
		exit(1);
	}
	fr.zoom = 1;
	fr.fl = -1;
	fr.filename = ft_strdup(argv[1]);
	fr.iter = 50;
	fr.wsize = 500;
	fr.zx = fr.wsize >> 1;
	fr.zy = fr.wsize >> 1;
	fr.mlx = mlx_init();
	fr.win = mlx_new_window(fr.mlx, fr.wsize, fr.wsize, "fractol");
	fr.img = mlx_new_image(fr.mlx, fr.wsize, fr.wsize);
	a = mlx_put_image_to_window(fr.mlx, fr.win, fr.img, 0, 0);
	mlx_hook(fr.win, 2, 0, key_func, &fr);
	mlx_hook(fr.win, 4, 0, mouse_func, &fr);
	mlx_hook(fr.win, 6, 0, hook_func, &fr);
	mlx_destroy_image(fr.mlx, fr.img);
	mlx_loop(fr.mlx);
	return (0);
}

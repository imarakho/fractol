/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 19:55:10 by imarakho          #+#    #+#             */
/*   Updated: 2017/03/10 13:44:48 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_fract *fr)
{
	int		i;

	fr->cy = -1;
	while (++fr->cy < fr->wsize)
	{
		fr->cx = -1;
		while (++fr->cx < fr->wsize)
		{
			fr->newr = 1.5 * (fr->cx - fr->zx) /
			((fr->wsize >> 1) * fr->zoom) + fr->movex;
			fr->newim = (fr->cy - fr->zy) /
			((fr->wsize >> 1) * fr->zoom) + fr->movey;
			i = -1;
			while (++i < fr->iter)
			{
				fr->oldr = fr->newr;
				fr->oldim = fr->newim;
				fr->newr = fr->oldr * fr->oldr - fr->oldim * fr->oldim + fr->cr;
				fr->newim = 2 * fr->oldr * fr->oldim + fr->cim;
				if (fr->newim * fr->newim + fr->newr * fr->newr > 4)
					break ;
			}
			drawing(fr, i, fr->cx, fr->cy);
		}
	}
}

void	check_julia(t_fract *fr, int key)
{
	key == 24 ? fr->iter += 10 : 0;
	key == 27 ? fr->iter -= 10 : 0;
	key == 123 ? fr->movex += 0.1 : 0;
	key == 124 ? fr->movex -= 0.1 : 0;
	key == 125 ? fr->movey -= 0.1 : 0;
	key == 126 ? fr->movey += 0.1 : 0;
	if (key == 18)
	{
		fr->cfl = 'g';
		fr->key = key;
	}
	if (key == 19)
	{
		fr->cfl = 'r';
		fr->key = key;
	}
	if (fr->key != 19 && fr->key != 18)
		fr->cfl = 'b';
	movejulia(fr);
}

void	movejulia(t_fract *fr)
{
	int		a;

	fr->cr = (double)fr->x / fr->wsize * 4 - 2;
	fr->cim = (double)fr->y / fr->wsize * 4 - 2;
	fr->img = mlx_new_image(fr->mlx, fr->wsize, fr->wsize);
	ft_julia(fr);
	a = mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
	mlx_destroy_image(fr->mlx, fr->img);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:12:44 by imarakho          #+#    #+#             */
/*   Updated: 2017/02/23 18:21:00 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_burnship(t_fract *fr)
{
	fr->cy = -1;
	while (++fr->cy < fr->wsize)
	{
		fr->cx = -1;
		while (++fr->cx < fr->wsize)
		{
			fr->cr = (fr->cx - fr->zx) /
			((fr->wsize >> 1) * fr->zoom) + fr->movex;
			fr->cim = (fr->cy - fr->zy) /
			((fr->wsize >> 1) * fr->zoom) + fr->movey;
			fr->newr = 0;
			fr->newim = 0;
			fr->i = -1;
			while (++fr->i < fr->iter)
			{
				fr->oldr = fr->newr;
				fr->oldim = fr->newim;
				fr->newr = fr->oldr * fr->oldr - fr->oldim * fr->oldim + fr->cr;
				fr->newim = fabs(2 * fr->oldr * fr->oldim) + fr->cim;
				if (fr->newim * fr->newim + fr->newr * fr->newr > 4)
					break ;
			}
			drawing(fr, fr->i, fr->cx, fr->cy);
		}
	}
}

void	check_burnship(t_fract *fr, int key)
{
	int		a;

	fr->img = mlx_new_image(fr->mlx, fr->wsize, fr->wsize);
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
	ft_burnship(fr);
	a = mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
	mlx_destroy_image(fr->mlx, fr->img);
}

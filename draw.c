/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarakho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 14:28:04 by imarakho          #+#    #+#             */
/*   Updated: 2017/02/23 17:59:16 by imarakho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_swap(unsigned short *a, unsigned short *b)
{
	unsigned short c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_draw_pixel(int x, int y, unsigned short *bgr, t_fract *fr)
{
	int		a;

	if (x <= 0 || y <= 0 || x >= fr->wsize || y >= fr->wsize)
		return ;
	fr->bpp = 0;
	fr->sizeline = 0;
	fr->endian = 0;
	fr->imbuf = mlx_get_data_addr(fr->img, &fr->bpp,
	&fr->sizeline, &fr->endian);
	a = (y * (fr->sizeline >> 2) + x) << 2;
	fr->imbuf[a] = bgr[0];
	fr->imbuf[a + 1] = bgr[1];
	fr->imbuf[a + 2] = bgr[2];
}

void	drawing(t_fract *fr, int i, int x, int y)
{
	fr->bgr[0] = 0;
	fr->bgr[1] = (i * 4) % 255;
	fr->bgr[2] = (i * 4) % 255;
	fr->cfl == 'g' ? ft_swap(&fr->bgr[0], &fr->bgr[1]) : 0;
	fr->cfl == 'r' ? ft_swap(&fr->bgr[0], &fr->bgr[2]) : 0;
	ft_draw_pixel(x, y, fr->bgr, fr);
}

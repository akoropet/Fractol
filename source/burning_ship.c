/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:17:44 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 19:41:58 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	calc_burning_ship(t_frac *frac)
{
	double	x;
	double	y;
	double	temp;
	int		iter;

	x = 0.0;
	y = 0.0;
	iter = 0;
	while (((x * x) + (y * y)) < 4.0 && iter < frac->iter)
	{
		temp = (x * x) - (y * y) + frac->c_re;
		y = 2 * fabs(x * y) + frac->c_im;
		x = temp;
		iter++;
	}
	if (iter < frac->iter)
		put_pixel_image(frac, frac->pixel_x, frac->pixel_y, iter * 0x02AFFF *
			abs(frac->color));
	else
		put_pixel_image(frac, frac->pixel_x, frac->pixel_y, 0x000000);
}

void	burning_ship(t_frac *frac)
{
	while (frac->pixel_y < WIN_Y && frac->pixel_y < (WIN_Y / THREAD *
		frac->thread))
	{
		frac->c_im = (frac->pixel_y - (WIN_Y / 2)) / (frac->zoom) +
			(frac->move_y);
		frac->pixel_x = 0;
		while (frac->pixel_x < WIN_X)
		{
			frac->c_re = (frac->pixel_x - (WIN_X / 2)) / (frac->zoom) +
				(frac->move_x);
			calc_burning_ship(frac);
			frac->pixel_x++;
		}
		frac->pixel_y++;
	}
}

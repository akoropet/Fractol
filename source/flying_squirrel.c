/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flying_squirrel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:53:05 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 19:42:08 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	calc_flying_squirrel(t_frac *frac, double x, double y)
{
	double	sqr_x;
	double	sqr_y;
	double	temp;
	int		iter;

	iter = 0;
	sqr_x = x * x;
	sqr_y = y * y;
	while (((sqr_x) + (sqr_y)) < 4.0 && iter < frac->iter)
	{
		temp = fabs(x * ((sqr_x * sqr_x) - (10 * sqr_x * sqr_y) +
			(5 * sqr_y * sqr_y))) + frac->c_re;
		y = -y * ((5 * sqr_x * sqr_x) - (10 * sqr_x * sqr_y) +
			(sqr_y * sqr_y)) + frac->c_im;
		x = temp;
		sqr_x = x * x;
		sqr_y = y * y;
		iter++;
	}
	if (iter < frac->iter)
		put_pixel_image(frac, frac->pixel_x, frac->pixel_y, iter * 0x02AFFF *
			abs(frac->color));
	else
		put_pixel_image(frac, frac->pixel_x, frac->pixel_y, 0x000000);
}

void	flying_squirrel(t_frac *frac)
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
			calc_flying_squirrel(frac, 0.0, 0.0);
			frac->pixel_x++;
		}
		frac->pixel_y++;
	}
}

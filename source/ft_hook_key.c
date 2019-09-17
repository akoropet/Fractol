/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:21:16 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 19:42:10 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		close_win(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		key_mouse(int button, int x, int y, t_data *data)
{
	t_frac	*frac;

	frac = data->frac[0];
	if ((button == 4) || (button == 5 && frac->zoom > 10))
	{
		if (button == 4)
		{
			frac->zoom *= 1.1;
			frac->move_x = (frac->move_x * frac->zoom +
				((x - (WIN_X / 2)) / 10)) / (frac->zoom);
			frac->move_y = (frac->move_y * frac->zoom +
				((y - (WIN_Y / 2)) / 10)) / (frac->zoom);
		}
		if (button == 5)
		{
			frac->zoom *= 0.9;
			frac->move_x = (frac->move_x * frac->zoom -
				((x - (WIN_X / 2)) / 10)) / (frac->zoom);
			frac->move_y = (frac->move_y * frac->zoom -
				((y - (WIN_Y / 2)) / 10)) / (frac->zoom);
		}
		ft_thread(data);
	}
	return (1);
}

void	key_move(t_frac *frac, int key)
{
	if (key == 123)
		frac->move_x = (frac->move_x * frac->zoom - 50) / frac->zoom;
	else if (key == 124)
		frac->move_x = (frac->move_x * frac->zoom + 50) / frac->zoom;
	else if (key == 126)
		frac->move_y = (frac->move_y * frac->zoom - 50) / frac->zoom;
	else if (key == 125)
		frac->move_y = (frac->move_y * frac->zoom + 50) / frac->zoom;
	else if (key == 121 && frac->zoom > 1)
		frac->zoom *= 0.9;
	else if (key == 116)
		frac->zoom *= 1.1;
	else if (key == 49 && frac->move_julia == 0)
		frac->move_julia = 1;
	else if (key == 49 && frac->move_julia == 1)
		frac->move_julia = 0;
}

int		key(int key, t_data *data)
{
	t_frac	*frac;

	frac = data->frac[0];
	if ((key >= 123 && key <= 126) || key == 121 || key == 116 || key == 49)
		key_move(frac, key);
	else if (key == 53)
		exit(0);
	else if (key == 69)
		frac->iter += 10;
	else if (key == 78 && frac->iter > 15)
		frac->iter -= 10;
	else if (key == 43)
	{
		frac->color = frac->color == -1 ? frac->color + 2 : frac->color + 1;
		if (frac->color >= 200)
			frac->color *= -1;
	}
	else if (key == 47)
	{
		frac->color = frac->color == 1 ? frac->color - 2 : frac->color - 1;
		if (frac->color <= -200)
			frac->color *= -1;
	}
	ft_thread(data);
	return (1);
}

int		move_mouse(int x, int y, t_data *data)
{
	t_frac	*frac;

	frac = data->frac[0];
	if (frac->move_julia == 1 && x >= 0 && y >= 0 && x < WIN_X && y < WIN_Y)
	{
		frac->cj_re = x * (frac->max_re - frac->min_re) / WIN_X + frac->min_re;
		frac->cj_im = y * (frac->max_im - frac->min_im) / WIN_Y + frac->min_im;
		ft_thread(data);
	}
	return (1);
}

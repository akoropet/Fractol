/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 22:18:46 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 19:49:57 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_copy(t_frac *src, t_frac *dst, int i)
{
	dst->mlx_ptr = src->mlx_ptr;
	dst->win_ptr = src->win_ptr;
	dst->arg = src->arg;
	dst->pixel_x = src->pixel_x;
	dst->pixel_y = WIN_Y / THREAD * i;
	dst->min_re = src->min_re;
	dst->max_re = src->max_re;
	dst->min_im = src->min_im;
	dst->max_im = src->max_im;
	dst->iter = src->iter;
	dst->c_re = src->c_re;
	dst->c_im = src->c_im;
	dst->zoom = src->zoom;
	dst->move_x = src->move_x;
	dst->move_y = src->move_y;
	dst->mzoom_x = src->mzoom_x;
	dst->mzoom_y = src->mzoom_y;
	dst->cj_re = src->cj_re;
	dst->cj_im = src->cj_im;
	dst->move_julia = src->move_julia;
	dst->color = src->color;
}

void	*ft_draw(void *param)
{
	t_frac	*frac;

	frac = (t_frac *)param;
	if (!ft_strcmp(frac->arg, "1"))
		mandelbrot(frac);
	if (!ft_strcmp(frac->arg, "2"))
		julia(frac);
	if (!ft_strcmp(frac->arg, "3"))
		burning_ship(frac);
	if (!ft_strcmp(frac->arg, "4"))
		fish(frac);
	if (!ft_strcmp(frac->arg, "5"))
		dipper(frac);
	if (!ft_strcmp(frac->arg, "6"))
		bird(frac);
	if (!ft_strcmp(frac->arg, "7"))
		flying_squirrel(frac);
	if (!ft_strcmp(frac->arg, "8"))
		elvis(frac);
	return (NULL);
}

void	ft_hook(t_data *data)
{
	if (!ft_strcmp(data->frac[0]->arg, "2"))
		mlx_hook(data->win_ptr, 6, 0, move_mouse, data);
	mlx_hook(data->win_ptr, 2, 0, key, data);
	mlx_hook(data->win_ptr, 17, 0, close_win, NULL);
	mlx_mouse_hook(data->win_ptr, key_mouse, data);
	mlx_loop(data->mlx_ptr);
}

void	ft_thread(t_data *data)
{
	int			i;
	pthread_t	thread[THREAD];

	i = 0;
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_X, WIN_Y);
	data->frac[0]->pixel_y = 0;
	while (i < THREAD)
	{
		i > 0 ? ft_copy(data->frac[i - 1], data->frac[i], i) : 0;
		data->frac[i]->img_ptr = data->img_ptr;
		pthread_create(&thread[i], NULL, ft_draw, data->frac[i]);
		i++;
	}
	i = 0;
	while (i < THREAD)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	ft_info(data);
	ft_hook(data);
}

void	put_pixel_image(t_frac *frac, int x, int y, int color)
{
	int				bpp;
	int				sl;
	int				e;
	char			*res;
	unsigned int	rgb;

	res = mlx_get_data_addr(frac->img_ptr, &bpp, &sl, &e);
	rgb = mlx_get_color_value(frac->mlx_ptr, color);
	if (x >= 0 && y >= 0 && x < WIN_X && y < WIN_Y)
		ft_memcpy((void *)(res + y * sl + x * bpp / 8), (void *)&rgb, 4);
}

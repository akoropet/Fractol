/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 03:36:17 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 19:42:20 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	reset(t_frac *frac, int i)
{
	frac->pixel_x = 0;
	frac->pixel_y = WIN_Y / THREAD * i;
	frac->min_re = -2.5;
	frac->max_re = 1.5;
	frac->min_im = -2.0;
	frac->max_im = 2.0;
	frac->iter = 100;
	frac->move_x = 0.0;
	frac->move_y = 0.0;
	frac->zoom = 200.0;
	frac->mzoom_x = 0;
	frac->mzoom_y = 0;
	frac->move_julia = 0;
	frac->cj_re = 0.0;
	frac->cj_im = 0.0;
	frac->thread = i + 1;
	frac->color = 10;
}

void	error(void)
{
	ft_putstr("Error input! Use one of the suggested arguments:\n");
	ft_putstr("1 - Mandelbrot\n");
	ft_putstr("2 - Julia\n");
	ft_putstr("3 - Burning ship\n");
	ft_putstr("4 - Fish\n");
	ft_putstr("5 - Dipper\n");
	ft_putstr("6 - Bird\n");
	ft_putstr("7 - Flying squirrel\n");
	ft_putstr("8 - Elvis\n");
}

void	ft_init_window(t_data *data, char *arg)
{
	data->arg = arg;
	if (!ft_strcmp(arg, "1"))
		data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_X, WIN_Y,
			"Fractol - Mandelbrot");
	else if (!ft_strcmp(arg, "2"))
		data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_X, WIN_Y,
			"Fractol - Julia");
	else if (!ft_strcmp(arg, "3"))
		data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_X, WIN_Y,
			"Fractol - Burning ship");
	else if (!ft_strcmp(arg, "4"))
		data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_X, WIN_Y,
			"Fractol - Fish");
	else if (!ft_strcmp(arg, "5"))
		data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_X, WIN_Y,
			"Fractol - Dipper");
	else if (!ft_strcmp(arg, "6"))
		data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_X, WIN_Y,
			"Fractol - Bird");
	else if (!ft_strcmp(arg, "7"))
		data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_X, WIN_Y,
			"Fractol - Flying squirrel");
	else if (!ft_strcmp(arg, "8"))
		data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_X, WIN_Y,
			"Fractol - Elvis");
}

int		ft_check_arg(char *arg)
{
	if (!ft_strcmp(arg, "1"))
		return (1);
	if (!ft_strcmp(arg, "2"))
		return (1);
	if (!ft_strcmp(arg, "3"))
		return (1);
	if (!ft_strcmp(arg, "4"))
		return (1);
	if (!ft_strcmp(arg, "5"))
		return (1);
	if (!ft_strcmp(arg, "6"))
		return (1);
	if (!ft_strcmp(arg, "7"))
		return (1);
	if (!ft_strcmp(arg, "8"))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	t_data		*data;
	int			i;

	if (ac == 2 && ft_check_arg(av[1]))
	{
		data = (t_data *)malloc(sizeof(t_data));
		data->frac = (t_frac **)malloc(sizeof(t_frac *) * THREAD);
		data->mlx_ptr = mlx_init();
		ft_init_window(data, av[1]);
		data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_X, WIN_Y);
		i = 0;
		while (i < THREAD)
		{
			data->frac[i] = (t_frac *)malloc(sizeof(t_frac));
			reset(data->frac[i], i);
			data->frac[i]->win_ptr = data->win_ptr;
			data->frac[i]->mlx_ptr = data->mlx_ptr;
			data->frac[i]->arg = av[1];
			i++;
		}
		ft_thread(data);
	}
	else
		error();
	return (0);
}

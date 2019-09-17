/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:17:58 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 19:42:13 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_info(t_data *data)
{
	int		n;

	n = 1;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 20 * n++, 0xFFFFFF,
		">>>>>>>>>>CONTROL KEYS<<<<<<<<<<");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 20 * n++, 0xFFFFFF,
		"");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 20 * n++, 0xFFFFFF,
		"'+' or '-' - Change iteration");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 20 * n++, 0xFFFFFF,
		"'Arrows' - Move fractol");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 20 * n++, 0xFFFFFF,
		"'PageUp' or 'PageDown' - Zoom");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 20 * n++, 0xFFFFFF,
		"Mouse scroll - Zoom in pointer");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 20 * n++, 0xFFFFFF,
		"'<' or '>' - Change color");
	if (!ft_strcmp(data->arg, "2"))
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 20 * n++, 0xFFFFFF,
			"Mouse move - Change Julia");
	if (!ft_strcmp(data->arg, "2"))
		mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 20 * n++, 0xFFFFFF,
			"'Scape' - Fixate the fractal");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 20 * n++, 0xFFFFFF,
		"'Esc' - Exit");
}

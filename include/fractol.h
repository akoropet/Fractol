/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoropet <akoropet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 03:33:57 by akoropet          #+#    #+#             */
/*   Updated: 2019/09/17 19:41:02 by akoropet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <pthread.h>

# define WIN_X 1000
# define WIN_Y 1000
# define THREAD 8

typedef struct		s_frac
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*arg;
	int				pixel_x;
	int				pixel_y;
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	int				iter;
	double			c_re;
	double			c_im;
	double			zoom;
	double			move_x;
	double			move_y;
	double			mzoom_x;
	double			mzoom_y;
	double			cj_re;
	double			cj_im;
	int				move_julia;
	int				color;
	int				thread;
}					t_frac;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*arg;
	t_frac			**frac;
}					t_data;

void				reset(t_frac *frac, int i);
void				error(void);
void				ft_init_window(t_data *data, char *arg);
int					ft_check_arg(char *arg);

void				ft_copy(t_frac *src, t_frac *dst, int i);
void				*ft_draw(void *param);
void				ft_hook(t_data *data);
void				ft_thread(t_data *data);
void				put_pixel_image(t_frac *frac, int x, int y, int color);

int					close_win(void *param);
int					key_mouse(int button, int x, int y, t_data *data);
void				key_move(t_frac *frac, int key);
int					key(int key, t_data *data);
int					move_mouse(int x, int y, t_data *data);

void				calc_mandelbrot(t_frac *frac);
void				mandelbrot(t_frac *frac);

void				calc_julia(t_frac *frac);
void				julia(t_frac *frac);

void				calc_burning_ship(t_frac *frac);
void				burning_ship(t_frac *frac);

void				calc_fish(t_frac *frac);
void				fish(t_frac *frac);

void				calc_dipper(t_frac *frac);
void				dipper(t_frac *frac);

void				calc_bird(t_frac *frac);
void				bird(t_frac *frac);

void				calc_flying_squirrel(t_frac *frac, double x, double y);
void				flying_squirrel(t_frac *frac);

void				calc_elvis(t_frac *frac, double x, double y);
void				elvis(t_frac *frac);

void				ft_info(t_data *data);

#endif

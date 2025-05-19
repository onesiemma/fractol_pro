/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ombatkam <ombatkam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:04:46 by ombatkam          #+#    #+#             */
/*   Updated: 2025/01/30 16:44:05 by ombatkam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ITER 100
# define WIDTH 200
# define HEIGHT 200
// # define X_MAX 4.0
// # define X_MIN -4.0
// # define Y_MAX 4.0
// # define Y_MIN -4.0

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "printf/ft_printf.h"
# include "libft/libft.h"
# include "minilibx/mlx_int.h"

typedef struct s_complex
{
	double	real;
	double	img;
}	t_complex;

typedef struct s_fractal
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_tmp;
	char		*addr;
	char		*tmp_addr;
	int			bpp;
	int			size_line;
	int			endian;
	t_complex	c;
	double		zoom;
	double		offset_x;
	double		offset_y;
	int			max_iter;
	int			current_iter;
	int			render_in_progress;
	int			type;
	int			height;
	int			width;
	int			color_shift;
}	t_fractal;

int			ft_julia_z(t_complex z0, t_complex c);
int			ft_fractal_bs(t_complex z0, t_complex c);
int			ft_set_color(int iter, int color_shift);
int			handle_mouse(int button, int x, int y, t_fractal *fractal);
int			ft_render_frame(t_fractal *fractal);
int			ft_fractal_type(char *s);
int			ft_is_number(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_correct_arg(char	**argv, int argc);
void		ft_draw_julia(t_fractal *fractal);
void		ft_draw_mandelbrot(t_fractal *fractal);
void		ft_draw_bs(t_fractal *fractal);
void		ft_hook_key(t_fractal *fractal);
void		ft_free_fractal(t_fractal *fractal);
void		ft_alloc_fractal(t_fractal *fractal, char *s);
double		ft_norm(t_complex z);
t_fractal	*ft_init_fractal(char **argv, int argc);
t_complex	ft_suite(t_complex z, t_complex c);
t_complex	ft_suite_bs(t_complex z, t_complex c);
t_complex	ft_conversion(int x, int y, t_fractal *fractal);
t_complex	ft_c_julia(const char *s1, const char *s2);

#endif

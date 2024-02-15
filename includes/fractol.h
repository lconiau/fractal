/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:48:33 by lconiau           #+#    #+#             */
/*   Updated: 2024/01/25 20:03:04 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h> 	

# define MDL_ERR "Please enter \n\t ./fractol mandelbrot or \n"
# define ERROR_MSG "\t./fractol julia <value_1> <value_2>"

# define WIDTH	800
# define HEIGHT 800
# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF
# define PURPLE	0x660066

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pxl_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iteration_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		color_start;
	int		color_end;
}			t_fractol;

t_complex		square_complex(t_complex z);
t_complex		sum_complex(t_complex z1, t_complex z2);
void			ft_putstr_fd(char *s, int fd);
void			data_init(t_fractol *fractal);
void			fractal_init(t_fractol *fractal);
void			fractal_render(t_fractol *fractal);
double			map(double unscal, double newmi, double newma, double old);
double			atodbl(char *s);
int				ft_strncmp(const char *first, const char *second, int lenght);
int				mouse_handler(int button, int x, int y, t_fractol *fractal);
int				julia_track(int x, int y, t_fractol *fractal);
int				close_handler(t_fractol *fractal);
int				key_handler(int keysym, t_fractol *fractal);

#endif

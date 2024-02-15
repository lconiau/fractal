/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:25:21 by lconiau           #+#    #+#             */
/*   Updated: 2024/01/25 19:32:46 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <X11/X.h>

int	close_handler(t_fractol *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

static void	mouse_interact(int x, int y, t_fractol *fractal)
{
	fractal->shift_y = (map(y, 2.5, -2.5, WIDTH) - fractal->shift_y)
		* 0.05 * fractal->zoom + fractal->shift_y;
	fractal->shift_x = (map(x, -2.5, 2.5, HEIGHT) - fractal->shift_x)
		* 0.05 * fractal->zoom + fractal->shift_x;
}

static void	key_move(int keysym, t_fractol *fractal)
{
	if (keysym == XK_1)
	{
		fractal->color_start = BLACK;
		fractal->color_end = PURPLE;
	}
	else if (keysym == XK_2)
	{
		fractal->color_start = RED;
		fractal->color_end = WHITE;
	}
	else if (keysym == XK_3)
	{
		fractal->color_start = BLUE;
		fractal->color_end = GREEN;
	}
	else if (keysym == XK_4)
	{
		fractal->color_start = rand();
		fractal->color_end = rand();
	}
	else if (keysym == XK_o)
		data_init(fractal);
}

int	key_handler(int keysym, t_fractol *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_equal)
		fractal->iteration_definition += 10;
	else if (keysym == XK_minus)
		fractal->iteration_definition -= 10;
	key_move(keysym, fractal);
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractal)
{
	if (button == Button5)
	{
		mouse_interact(x, y, fractal);
		fractal->zoom *= 1.05;
	}
	else if (button == Button4)
	{
		mouse_interact(x, y, fractal);
		fractal->zoom *= 0.95;
	}
	fractal_render(fractal);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <lconiau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:47:26 by lconiau           #+#    #+#             */
/*   Updated: 2024/03/14 07:28:04 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		j += write(fd, &s[i], 1);
		i++;
	}
	(void)j;
}

int	ft_strncmp(const char *first, const char *second, int lenght)
{
	while (lenght--)
	{
		if (*first != *second)
			return ((unsigned char)*first - (unsigned char)*second);
		if (*first == '\0')
			break ;
		first++;
		second++;
	}
	return (0);
}

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

int	julia_track(int x, int y, t_fractol *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5) && fractal->islock == 0)
	{
		fractal->julia_x = (map(x, -2, +2, WIDTH) * fractal->zoom);
		fractal->julia_y = (map(y, +2, -2, WIDTH) * fractal->zoom);
		fractal_render(fractal);
	}
	return (0);
}

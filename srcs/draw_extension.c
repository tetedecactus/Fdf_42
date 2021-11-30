/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_extension.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:35:34 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/20 11:31:05 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_fdf *data, unsigned int x, unsigned int y,
	unsigned int color)
{
	if (x < WIDTH && y < HEIGHT)
	{
		data->mlx.addr[(x * 4) + (y * WIDTH_IMG * 4)] = color % 256;
		data->mlx.addr[(x * 4) + (y * WIDTH_IMG * 4) + 1] = color / 256;
		data->mlx.addr[(x * 4) + (y * WIDTH_IMG * 4) + 2] = color / (256 * 256);
	}
}

float	mod(float i)
{
	if (i < 0)
		i = -i;
	return (i);
}

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->move.rotation_cos);
	*y = (*x + *y) * sin(data->move.rotation_sin) - z;
}

void	clear_image(char *addr)
{
	int	count;

	count = 0;
	while (count < (WIDTH_IMG * HEIGHT_IMG * 4))
		addr[count++] = 0;
}

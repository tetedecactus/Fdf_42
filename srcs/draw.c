/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:05:37 by olabrecq          #+#    #+#             */
/*   Updated: 2021/10/20 14:35:57 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

void	my_mlx_pixel_put(fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

float mod(float i)
{
	return ((i < 0) ? -i : i);
}

void bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float x_step;
	float y_step;
	int max;

	x_step = x1 - x;
	y_step = y1 - y;
	
	max = fmax(mod(x_step), mod(y_step));
	
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		my_mlx_pixel_put(data->img, x, y, WHITE);
		x += x_step;
		y += y_step;
	}
}

int del_key(int key)
{
	printf("%d", key);
	return (0);
}

void draw_matrix(void)
{
	fdf *data;
	
	//data = NULL;
	data = (fdf*)malloc(sizeof(fdf));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HIGH, "FDF");
	//data->img = mlx_new_image(data->mlx_ptr, WIDTH, HIGH);
	//data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	//my_mlx_pixel_put(data->img, 450, 300, WHITE);
	bresenham(10, 10, 600, 300, data);
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	mlx_key_hook(data->win_ptr, del_key, NULL);
	mlx_loop(data->mlx_ptr);
} 
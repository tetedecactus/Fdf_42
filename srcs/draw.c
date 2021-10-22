/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:05:37 by olabrecq          #+#    #+#             */
/*   Updated: 2021/10/22 11:17:15 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

float mod(float i)
{
	return ((i < 0) ? -i : i);
}

void isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.523599);
	*y = (*x + *y) * sin(0.523599) - z;

}

void bresenham(float x, float y, float x1, float y1, fdf *data, t_point **matrix)
{
	float x_step;
	float y_step;
	int max;
	int z;
	int z1;

	z = matrix[(int)y][(int)x].z;
	z1 = matrix[(int)y1][(int)x1].z;
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	data->color = (z) ? RED : WHITE;
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	x += 350;
	y += 150;
	x1 += 350;
	y1 += 150;

	x_step = x1 - x;
	y_step = y1 - y;
	max = fmax(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

int del_key(int key)
{
	printf("%d", key);
	return (0);
}

void draw(fdf *data, t_map *map_info, t_point **matrix)
{
	int x;
	int y;
	
	y = 0;
	while ( y < map_info->height)
	{
		x = 0;
		while (x < map_info->width)
		{
			if (x < map_info->width - 1)
				bresenham(x, y, x + 1, y, data, matrix);
			if (y < map_info->height - 1)
				bresenham(x, y, x, y + 1, data, matrix);
			x++;
		}
		y++;
	}
}

void draw_matrix(t_map *map_info, t_point **matrix)
{
	fdf *data;
	
	data = NULL;
	data = (fdf*)malloc(sizeof(fdf));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FDF");
	//data->img = mlx_new_image(data->mlx_ptr, WIDTH_IMG, HEIGHT_IMG);
	//data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	//my_mlx_pixel_put(data->img, 450, 300, WHITE);`
	//bresenham(10, 10, 600, 300, data);
	data->zoom = 20;
	draw(data, map_info, matrix);
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	mlx_key_hook(data->win_ptr, del_key, NULL);
	mlx_loop(data->mlx_ptr);
} 
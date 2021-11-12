/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:05:37 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/12 10:47:00 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

float mod(float i)
{
	if (i < 0)
		i = -i;
	return(i);
	//return ((i < 0) ? -i : i);
}

void isometric(float *x, float *y, int z, fdf *data)
{
	// Besoin de changer les parametre pour seulement fdf *data
	// Same pour bresenham function
	*x = (*x - *y) * cos(data->rotation_cos);
	*y = (*x + *y) * sin(data->rotation_sin) - z;
}

void bresenham(float x, float y, float x1, float y1, fdf *data)
{
	// besoin de changer les param
	float x_step;
	float y_step;
	int max;
	int z;
	int z1;

	z = (data->matrix[(int)y][(int)x].z) * (data->projection);
	z1 = (data->matrix[(int)y1][(int)x1].z) * (data->projection);
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	data->color = (z || z1) ? MYSTERE : WHITE;
	isometric(&x, &y, z, data);
	isometric(&x1, &y1, z1, data);
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
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

void draw(fdf *data)
{
	int x;
	int y;
	
	y = 0;
	while ( y < data->map_height)
	{
		x = 0;
		while (x < data->map_width[y])
		{
			if (x < *data->map_width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->map_height - 1 /*&& (data->map_width[y] >= x && y <= data->map_height)*/)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}

// void check_zoom(fdf *data)
// {
// 	if (data->map_height > 200 &&  *data->map_width > 200)
// 		data->zoom = 2;
// 	else if (data->map_height >= 200 &&  *data->map_width >= 200)
// 		data->zoom = 5;
// 	else if (data->map_height >= 100)
// 		data->zoom = 7;
// 	else if (data->map_height > 50 &&  *data->map_width > 50)
// 		data->zoom = 8;
// 	else if (data->map_height == 50 &&  *data->map_width == 50)
// 		data->zoom = 12;
// 	else
// 		data->zoom = 20;
// 	printf(" zoom = %d\n", data->zoom);
// }

void draw_matrix(fdf *data)
{
	// fdf *data;
	
	// data = NULL;
	// data = (fdf*)malloc(sizeof(fdf));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FDF");
	// data->img = mlx_new_image(data->mlx_ptr, WIDTH_IMG, HEIGHT_IMG);
	// data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	//my_mlx_pixel_put(data->img, 450, 300, WHITE);`
	//bresenham(10, 10, 600, 300, data);
	init_data(data);
	//check_zoom(data);
	draw(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	mlx_key_hook(data->win_ptr, check_key, data);
	mlx_loop(data->mlx_ptr);
	free(data);
} 
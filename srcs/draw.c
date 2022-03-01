/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:05:37 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/28 15:33:15 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	bresenham_extension(t_fdf*data)
{
	data->move.max = fmax(mod((int)data->move.x_step),
			mod((int)data->move.y_step));
	data->move.x_step /= data->move.max;
	data->move.y_step /= data->move.max;
}

void	bresenham_x(float x, float y, float x1, t_fdf *data)
{
	float	y1;
 
	y1 = y;
	set_z(x, y, data);
	set_z1(x1, y1, data);
	x *= data->move.zoom;
	y *= data->move.zoom;
	x1 *= data->move.zoom;
	y1 *= data->move.zoom;
	data->move.color = set_color(data->move.z, data->move.z1);
	isometric(&x, &y, data->move.z, data);
	isometric(&x1, &y1, data->move.z1, data);
	x += data->move.shift_x;
	y += data->move.shift_y;
	x1 += data->move.shift_x;
	y1 += data->move.shift_y;
	data->move.x_step = x1 - x;
	data->move.y_step = y1 - y;
	bresenham_extension(data);
	while ((int)(x - x1) || (int)(y - y1))
	{
		my_mlx_pixel_put(data, x, y, data->move.color);
		x += data->move.x_step;
		y += data->move.y_step;
	}
}

void	bresenham_y(float x, float y, float y1, t_fdf *data)
{
	float	x1;

	x1 = x;
	set_z(x, y, data);
	set_z1(x1, y1, data);
	x *= data->move.zoom;
	y *= data->move.zoom;
	x1 *= data->move.zoom;
	y1 *= data->move.zoom;
	data->move.color = set_color(data->move.z, data->move.z1);
	isometric(&x, &y, data->move.z, data);
	isometric(&x1, &y1, data->move.z1, data);
	x += data->move.shift_x;
	y += data->move.shift_y;
	x1 += data->move.shift_x;
	y1 += data->move.shift_y;
	data->move.x_step = x1 - x;
	data->move.y_step = y1 - y;
	bresenham_extension(data);
	while ((int)(x - x1) || (int)(y - y1))
	{
		my_mlx_pixel_put(data, x, y, data->move.color);
		x += data->move.x_step;
		y += data->move.y_step;
	}
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	clear_image(data->mlx.addr);
	while (y < data->info.map_height)
	{
		x = 0;
		while (x < data->info.map_width[(int)y])
		{
			if (x < *data->info.map_width - 1)
				bresenham_x(x, y, x + 1, data);
			if (y < data->info.map_height - 1)
				bresenham_y(x, y, y + 1, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx.mlx_ptr,
		data->mlx.win_ptr, data->mlx.img, 0, 0);
}

void	draw_matrix(t_fdf *data)
{
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr, WIDTH, HEIGHT, "FDF");
	init_data(data);
	data->mlx.img = mlx_new_image(data->mlx.mlx_ptr, WIDTH_IMG, HEIGHT_IMG);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img,
			&data->mlx.bits_per_pixel,
			&data->mlx.line_length, &data->mlx.endian);
	set_zoom(data);
	draw(data);
	mlx_key_hook(data->mlx.win_ptr, check_key, data);
	mlx_loop(data->mlx.mlx_ptr);
	free(data); 
}

// void bresenham(float x, float y, float x1, float y1, fdf *data)
// {
// 	float x_step;
// 	float y_step;
// 	int max;
// 	int z;
// 	int z1;

// 	z = (data->matrix[(int)y][(int)x].z) * (data->projection);
// 	z1 = (data->matrix[(int)y1][(int)x1].z) * (data->projection);
// 	x *= data->zoom;
// 	y *= data->zoom;
// 	x1 *= data->zoom;
// 	y1 *= data->zoom;
// 	data->color = (z || z1) ? MYSTERE : WHITE;
// 	isometric(&x, &y, z, data);
// 	isometric(&x1, &y1, z1, data);
// 	x += data->shift_x;
// 	y += data->shift_y;
// 	x1 += data->shift_x;
// 	y1 += data->shift_y;
// 	x_step = x1 - x;
// 	y_step = y1 - y;
// 	max = fmax(mod(x_step), mod(y_step));
// 	x_step /= max;
// 	y_step /= max;
// 	while ((int)(x - x1) || (int)(y - y1))
// 	{
// 		//mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
// 		// my_mlx_pixel_put(data, x, y, data->color);
// 		my_mlx_pixel_put(data, x, y, WHITE);
// 		x += x_step;
// 		y += y_step;
// 	}
// }
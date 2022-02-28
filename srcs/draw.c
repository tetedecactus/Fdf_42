/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:05:37 by olabrecq          #+#    #+#             */
/*   Updated: 2022/02/28 11:02:39 by olabrecq         ###   ########.fr       */
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
	// isometric(&x, &y, data->move.z, data);
	// isometric(&x1, &y1, data->move.z1, data);
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
	// isometric(&x, &y, data->move.z, data);
	// isometric(&x1, &y1, data->move.z1, data);
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


//----------------------
// // Draw minimap
// 	int minmapSize = (int)(screenHeight * 0.25) / mapHeight;

// 	for (int x = 0; x < minmapSize * mapHeight + 10; x++)
// 	for (int y = 0; y < minmapSize * mapWidth + 10; y++)
// 		my_mlx_pixel_put(lode->img[1], y, x, 153);

// 	for (int x = 0; x < mapHeight; x++)
// 	for (int y = 0; y < mapWidth; y++){
// 		for (int i = 0; i < minmapSize; i++)
// 		for (int j = 0; j < minmapSize; j++){
// 			if (worldMap[y][x])
// 				my_mlx_pixel_put(lode->img[1], 5 + (x * minmapSize) + i, 5 + (y * minmapSize) + j, 0);
// 			else
// 				my_mlx_pixel_put(lode->img[1], 5 + (x * minmapSize) + i, 5 + (y * minmapSize) + j, RGB_White);
// 		}
// 	}

// 	int posPlayerX = 5 + (int)(lode->posX * minmapSize) - 3;
// 	int posPlayerY = 5 + (int)(lode->posY * minmapSize) - 3;

// 	for (int x = 0; x < 7; x++)
// 	for (int y = 0; y < 7; y++)
		// my_mlx_pixel_put(lode->img[1], posPlayerY + y, posPlayerX + x, RGB_Red);



void	draw_minimap(t_cub *cub)
{
    int	x;
    int	y;
	
	clear_image(cub->img[0]->endian);
	y = 0;
	while (y < cub->map_height)
	{
		x = 0;
		while (x < cub->map_width)
		{
			if (x < cub->map_width - 1)
				bresenham_x(x, y, x + 1, cub);
			if (y < cub->map_height - 1)
				bresenham_y(x, y, y + 1, cub);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img[0]->img, 0, 0);
}

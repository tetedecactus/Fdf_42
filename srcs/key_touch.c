/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_touch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:10:01 by olabrecq          #+#    #+#             */
/*   Updated: 2022/03/01 08:55:20 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	shift_key(int key, t_fdf *data)
{
	if (key == LEFT)
		data->move.shift_x -= 10;
	if (key == RIGHT)
		data->move.shift_x += 10;
	if (key == DOWN)
		data->move.shift_y += 10;
	if (key == UP)
		data->move.shift_y -= 10;
	draw(data);
}

void	projection_key(int key, t_fdf *data)
{
	if (key == ZOOM_OUT)
		data->move.projection -= 1;
	if (key == ZOOM_IN)
		data->move.projection += 1;
	draw(data);
}

void	rotation_key(int key, t_fdf *data)
{
	if (key == 8)
		data->move.rotation_cos += 0.2;
	if (key == 1)
		data->move.rotation_sin += 0.2;
	if (key == 0)
		data->move.rotation_cos -= 0.2;
	if (key == 7)
		data->move.rotation_sin -= 0.2;
	draw(data);
}

void	zoom_key(int key, t_fdf *data)
{
	if (key == 24)
		data->move.zoom += 1;
	if (key == 27)
		data->move.zoom -= 1;
	draw(data);
}

// Mac keys
// int	check_key(int key, t_fdf *data)
// {
// 	if (key >= 123 && key <= 126)
// 		shift_key(key, data);
// 	if (key == 37 || key == 46)
// 		projection_key(key, data);
// 	if (key == 8 || key == 7 || key == 0 || key == 1)
// 		rotation_key(key, data);
// 	if (key == 24 || key == 27)
// 		zoom_key(key, data);
// 	if (key == 53)
// 	{
// 		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
// 		exit(0);
// 	}
// 	return (0);
// }

// Linuix key
int	check_key(int key, t_fdf *data)
{
	if (key >= 65361 && key <= 65264)
		shift_key(key, data);
	if (key == 0 || key == 2)
		projection_key(key, data);
	if (key == 8 || key == 7 || key == 0 || key == 1)
		rotation_key(key, data);
	if (key == 24 || key == 27)
		zoom_key(key, data);
	if (key == 65307)
	{
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
		exit(0);
	}
	return (0);
}
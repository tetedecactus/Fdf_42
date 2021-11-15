/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_touch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:10:01 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/15 14:51:37 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"


void del_key(fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

void shift_key(int key, fdf *data)
{
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 126)
		data->shift_y -= 10;
	//mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
}

void projection_key(int key, fdf *data)
{
	if (key == 37)
		data->projection -= 1;
	if (key == 46)
		data->projection += 1;
	//mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
}

void rotation_key(int key, fdf *data)
{
	if (key == 8)
		data->rotation_cos += 0.2;
	if (key == 1)
		data->rotation_sin += 0.2;
	if (key == 0)
		data->rotation_cos -= 0.2;
	if (key == 7)
		data->rotation_sin -= 0.2;
	//mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
}

void zoom_key(int key, fdf *data)
{
	if (key == 24)
		data->zoom += 1;
	if (key == 27)
		data->zoom -= 1;
	//mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
}

int check_key(int key, fdf *data)
{
	if (key == 53)
		del_key(data);
	if (key >= 123 && key <= 126)
		shift_key(key, data);
	if (key == 37 || key == 46)
		projection_key(key, data);
	if (key == 8 || key == 7 || key == 0 || key == 1)
		rotation_key(key, data);
	if (key == 24 || key == 27)
		zoom_key(key, data);
	
	return (0);
}
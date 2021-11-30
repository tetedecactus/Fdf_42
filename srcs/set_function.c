/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:07:38 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/20 11:17:07 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

unsigned int	set_color(int z, int z1)
{
	if (z || z1)
		return ((int)RED);
	else
		return ((int)WHITE);
}

void	set_zoom(t_fdf *data)
{
	if (data->info.map_height > 200 && *data->info.map_width > 200)
		data->move.zoom = 2;
	else if (data->info.map_height >= 200 && *data->info.map_width >= 200)
		data->move.zoom = 5;
	else if (data->info.map_height >= 100)
		data->move.zoom = 7;
	else if (data->info.map_height > 50 && *data->info.map_width > 50)
		data->move.zoom = 8;
	else if (data->info.map_height == 50 && *data->info.map_width == 50)
		data->move.zoom = 12;
	else
		data->move.zoom = 20;
}

void	set_z(float x, float y, t_fdf *data)
{
	data->move.z = (data->matrix[(int)y][(int)x].z)
		* (data->move.projection);
}

void	set_z1(float x1, float y1, t_fdf *data)
{
	data->move.z1 = (data->matrix[(int)y1][(int)x1].z)
		* (data->move.projection);
}

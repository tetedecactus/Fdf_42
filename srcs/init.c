/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:18:47 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/20 11:29:31 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_matrix(t_point *parameters)
{
	parameters->x = 0.000000;
	parameters->y = 0.000000;
	parameters->z = 0.00000;
}

void	init_map(t_fdf *data, int line_width)
{
	data->info.map_width = ft_calloc(1, (sizeof(int) * (line_width * 2)));
	data->info.map_height = 0;
}

void	init_data(t_fdf *data)
{
	data->move.color = (int)0xffffff;
	data->move.rotation_cos = 0.623599;
	data->move.rotation_sin = 0.623599;
	data->move.shift_x = 850;
	data->move.shift_y = 150;
	data->move.projection = 1;
	data->move.x_step = 0.0;
	data->move.y_step = 0.0;
	data->move.max = 0;
	data->move.z = 0;
	data->move.z1 = 0;
}

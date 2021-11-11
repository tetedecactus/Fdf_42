/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:18:47 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/11 11:33:04 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_matrix(t_point *parameters)
{
	parameters->x = 0.000000;
	parameters->y = 0.000000;
	parameters->z = 0.00000;
	parameters->col = 0.000000;
	parameters->row = 0.000000;
	parameters->color = 0.000000;
}

void init_map(fdf *data, int line_width)
{
	data->map_width = ft_calloc(1, (sizeof(int) * line_width));
	data->map_height = 0;
}

void init_data(fdf *data)
{
	data->rotation_cos = 0.623599;
	data->rotation_sin = 0.623599;
	data->shift_x = 850;
	data->shift_y = 150;
	data->projection = 1;
}
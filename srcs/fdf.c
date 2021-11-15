/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:32:43 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/15 16:56:35 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	matrix_the_fifth_delallocated(fdf *data)
{
	int	i;
	int	height;

	height = data->map_height;
	i = 0;
	while (i < height)
		free(data->matrix[i++]);
	free(data->matrix);
}

int	main(int argc, char **argv)
{
	fdf	*data;

	data = NULL;
	data = (fdf *)malloc(sizeof(fdf));
	if (argc != 2)
		error_message(2);
	get_height_n_width(argv[1], data);
	data->matrix = alloc_matrix(data);
	data->matrix = create_fdf_matrix(argv[1], data);
	draw_matrix(data);
	matrix_the_fifth_delallocated(data);
	free(data);
	return (0);
}

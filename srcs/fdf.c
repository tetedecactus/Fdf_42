/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:32:43 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/22 10:55:59 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	matrix_the_fifth_delallocated(t_fdf *data)
{
	int	i;
	int	height;

	height = data->info.map_height;
	i = 0;
	while (i < height)
		free(data->matrix[i++]);
	free(data->matrix);
}

void	get_height_n_width_extension(int fd, char *line, t_fdf *data)
{
	int		old_width;
	int		i;

	i = 0;
	old_width = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (!old_width)
			old_width = width_counter(line, ' ');
		if (!i)
		{
			init_map(data, old_width);
			data->info.map_width[0] = old_width;
			i++;
		}
		else
			data->info.map_width[i++] = width_counter(line, ' ');
		data->info.map_height++;
		free(line);
	}
	free(line);
}

void	get_height_n_width(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(file_name, O_RDWR);
	if (fd <= 0)
		error_message(4);
	get_height_n_width_extension(fd, line, data);
	if (close(fd))
		error_message(5);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	data = NULL;
	data = (t_fdf *)malloc(sizeof(t_fdf));
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

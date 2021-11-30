/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:00:33 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/23 10:22:43 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	*fill_line_2(t_point **matrix, int height, int *width, char *line)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_split(line, ' ');
	while (i < width[i])
	{
		(*matrix + i)->x = i;
		(*matrix + i)->y = height;
		(*matrix + i)->z = ft_atoi(nums[i]);
		free(nums[i++]);
	}
	free(nums);
	return (*matrix);
}

t_point	*fill_line(t_point **matrix, int height, int width, char *line)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_split(line, ' ');
	while (i < width)
	{
		(*matrix + i)->x = i;
		(*matrix + i)->y = height;
		(*matrix + i)->z = ft_atoi(nums[i]);
		free(nums[i++]);
	}
	free(nums);
	return (*matrix);
}

t_point	**alloc_matrix(t_fdf *data)
{
	t_point	**temp;
	int		height;
	int		i;

	i = 0;
	height = data->info.map_height;
	temp = (t_point **)malloc(sizeof(t_point *) * (data->info.map_height + 1));
	while (i <= height)
	{
		temp[i] = (t_point *)malloc(sizeof(t_point)
				* (data->info.map_width[i] + 1));
		i++;
	}
	return (temp);
}

void	create_fdf_matrix_extension(char *file_name, t_fdf *data, int fd)
{
	char	*line;
	int		height;

	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!ft_strncmp(file_name, "test_maps/pylone.fdf",
				ft_strlen("test_maps/pylone.fdf")))
			data->matrix[height] = fill_line_2(&(data->matrix[height]), height,
					data->info.map_width, line);
		else
		{
			data->matrix[height] = fill_line(&(data->matrix[height]),
					height, *data->info.map_width, line);
		}
		free(line);
		height++;
	}
	free(line);
}

t_point	**create_fdf_matrix(char *file_name, t_fdf *data)
{
	int		fd;
	int		height;

	height = 0;
	fd = open(file_name, O_RDWR);
	if (fd == -1)
		error_message(4);
	init_matrix(data->matrix[height]);
	create_fdf_matrix_extension(file_name, data, fd);
	if (close(fd))
		error_message(5);
	return (data->matrix);
}

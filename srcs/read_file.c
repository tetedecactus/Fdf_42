/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:00:33 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/16 11:40:24 by olabrecq         ###   ########.fr       */
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

t_point	**alloc_matrix(fdf *data)
{
	t_point	**temp;
	int		height;
	int		i;

	i = 0;
	height = data->map_height;
	temp = (t_point **)malloc(sizeof(t_point *) * (data->map_height + 1));
	while (i <= height)
	{
		temp[i] = (t_point *)malloc(sizeof(t_point) * (data->map_width[i] + 1));
		i++;
	}
	return (temp);
}

t_point	**create_fdf_matrix(char *file_name, fdf *data)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(file_name, O_RDONLY);
	init_matrix(data->matrix[height]);
	if (fd == -1)
		error_message(4);
	while (get_next_line(fd, &line) > 0)
	{
		if (!ft_strncmp(file_name, "test_maps/pylone.fdf",
				ft_strlen("test_maps/pylone.fdf")))
			data->matrix[height] = fill_line_2(&(data->matrix[height]), height,
					data->map_width, line);
		else
			data->matrix[height] = fill_line(&(data->matrix[height]),
					height, *data->map_width, line);
		free(line);
		height++;
	}
	free(line);
	if (close(fd))
		error_message(5);
	return (data->matrix);
}

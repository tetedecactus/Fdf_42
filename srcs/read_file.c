/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:00:33 by olabrecq          #+#    #+#             */
/*   Updated: 2021/10/20 20:14:45 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_height_n_width(char *file_name, t_map *map)
{
	int		fd;
	char	*line;
	int		old_width;

	old_width = 0;
	fd = open(file_name, O_RDONLY);
	init_map(map);
	if (fd <= 0)
		error_message(4);
	while ((get_next_line(fd, &line)) > 0)
	{
		map->width = width_counter(line, ' ');
		if (old_width != 0 && old_width != map->width)
			error_message(1);
		old_width = map->width;
		map->height++;
		free(line);
	}
	free(line);
	if (close(fd))
		error_message(5);
}

void	init_matrix(t_point *parameters)
{
	parameters->x = 0.000000;
	parameters->y = 0.000000;
	parameters->z = 0.00000;
	parameters->col = 0.000000;
	parameters->row = 0.000000;
	//parameters->color = 0.000000;
}

void	fill_line(t_point **matrix, int height, int width, char *line)
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
}

t_point	**alloc_matrix(t_map *map)
{
	t_point	**temp;
	int		height;

	height = map->height;
	temp = (t_point **)malloc(sizeof(t_point *) * (map->height + 1));
	while (height >= 0)
		temp[height--] = (t_point *)malloc(sizeof(t_point) * (map->width + 1));
	return (temp);
}

t_point	**create_fdf_matrix(char *file_name, t_point **matrix, t_map *map)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_message(4);
	init_matrix(matrix[0]);
	while (get_next_line(fd, &line) > 0)
	{
		fill_line(&(matrix[height]), height, map->width, line);
		free(line);
		height++;
	}
	free(line);
	if (close(fd))
		error_message(5);
	return (matrix);
}

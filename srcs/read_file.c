/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:00:33 by olabrecq          #+#    #+#             */
/*   Updated: 2021/10/15 11:18:29 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float t_width;
float t_height;

fdf     **alloc_and_height_fdf_map(char *file_name)
{
    int     fd;
    char    *line;
    int     old_width;
    int     width = 0;
    int     height = 0;
    fdf     **temp;

    t_width = 0;
    t_height = 0;
    old_width = 0;
    fd = open(file_name, O_RDONLY);
    if (fd <= 0)
        error_message(4);
    while ((get_next_line(fd, &line)) > 0)
    {
        width = width_counter(line, ' ');
        if (old_width != 0 && old_width != width)
            error_message(1);
        old_width = width;
        height++;
        free(line);
    }
    free(line);
    if (close(fd))
        error_message(5);
    t_height = height;
    t_width = width;
    temp = (fdf **)malloc(sizeof(fdf *) * (height + 1));
    while (height >= 0)
        temp[height--] = (fdf *)malloc(sizeof(fdf) * (width + 1));
    return (temp);
}

void    init_matrix(fdf *parameters)
{
    parameters->x = 0.000000;
    parameters->y = 0.000000;
    parameters->z = 0.00000;
    parameters->col = 0.000000;
    parameters->row = 0.000000;
    parameters->color = 0.000000;
    parameters->height = t_height;
    parameters->width = t_width;
    //parameters->endian = 0;
    //parameters->img = 0;
    //parameters->line_length = 0;
    //parameters->line_length = 0;
    //parameters->mlw_win_ptr = 0;
    //parameters->mlx_ptr = 0;
}

void fill_line(fdf **matrix, int height, int width, char *line)
{
    char **nums;
    int i = 0;
    
    nums = ft_split(line, ' ');
    while (i < width)
    {
        (*matrix + i)->x = i;
        (*matrix + i)->y = height;
        (*matrix + i)->z = ft_atoi(nums[i]);
        free(nums[i++]);
    }
    
}

fdf **create_fdf_map(char *file_name, fdf **matrix)
{
    int     fd;
    char    *line;
    int     height;
    
    height = 0;
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        error_message(4);
    while (get_next_line(fd, &line) > 0)
    {
        fill_line(&(matrix[height]), height, t_width, line);
        free(line);
        height++;
    }
    free(line);
    if (close(fd))
        error_message(5);
    return (matrix);
}

void print_matrix(fdf **matrix)
{
    int i;
    int j;
	
    i = 0;
    while (i < t_height)
    {
        j = 0;
        while (j < t_width)
        {
            printf("%3.0f", matrix[i][j].z);
            j++;
        }
        printf("\n");
        i++;
    }
}

// void    read_n_create_map(char *file_name, fdf **matrix);
// {
//     alloc_and_height_fdf_map(file_name)
//     //create_fdf_map(file_name, map);    
//     printf("height = %d\n", map->height);
//     printf("width = %d\n", map->width);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:00:33 by olabrecq          #+#    #+#             */
/*   Updated: 2021/10/13 15:10:24 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void get_height_n_width(char *file_name, fdf *map)
{
    int     fd;
    char    *line;
    int     old_width;

    old_width = 0;
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        error_message(4);
    while (get_next_line(fd, &line) > 0)
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

fdf **alloc_fdf_map(fdf *map)
{
    fdf     **matrix;
    int height;

    height = map->height;
    matrix = (fdf **)malloc(sizeof(fdf *) * map->height);
    while (map->height > 0)
        matrix[height--] = malloc(sizeof(fdf) * map->width);
    return (matrix);
}

void fill_line(fdf **matrix, int height, int width, char *line)
{
    char **nums;

    nums = ft_split(line, ' ');
    while (matrix[width--])
    {
        matrix[height][width].x = width;
        matrix[height][width].y = height;
        matrix[height][width].z = ft_atoi(&nums[height][width]);
    }
}

fdf **create_fdf_map(char *file_name, fdf *map)
{
    int     fd;
    char    *line;
    fdf     **matrix;
    int     height;
    
    height = 0;
    matrix = alloc_fdf_map(map);
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        error_message(4);
    while (get_next_line(fd, &line) > 0)
    {
        fill_line(matrix, height, map->width, line);
        free(line);
        height++;
    }
    free(line);
    if (close(fd))
        error_message(5);
    return (matrix);
}

void read_n_create_map(char *file_name, fdf *map)
{
    // 1st get width and height
    get_height_n_width(file_name, map);
    // 2st malloc all this shit (space for map shit)
    alloc_fdf_map(map);
    // 3st create and put data into my map shit
    printf("height = %d\n", map->height);
    printf("width = %d\n", map->width);
}


// OLD SHITTI SHIT

// void read_file(char *file_name, map *map)
// {
//     int fd;
//     char *line;
//     int i;
    
//     map->height = get_height(file_name);
//     map->width = get_width(file_name);
//     printf("inside read_file\n");
//     map->matrix = (int **)malloc(sizeof(int*) * (map->height + 1));
//     printf("1st malloc done\n");   
//     i = 0;
//     while (i <= map->height) 
//         map->matrix[i++] = (int*)malloc(sizeof(int) * (map->width + 1));
//     printf("2st malloc done\n");
//     fd = open(file_name, O_RDONLY);
//     i = 0;
//     while (get_next_line(fd, &line) > 0)
//     {
//         fill_matrix(map->matrix[i], line, map);
//         free(line);
//         i++;
//     }
//     close(fd);
//     map->matrix[i] = NULL;
// }
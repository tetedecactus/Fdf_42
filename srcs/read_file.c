/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:00:33 by olabrecq          #+#    #+#             */
/*   Updated: 2021/10/02 13:06:13 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int get_height(char *file_name)
{
    int height;
    int fd = 0;
    char *line;
    
    fd = open(file_name, fd);
    if (fd == -1)
        error_message();
    height = 0;
    while (get_next_line(fd, &line) > 0)
    {
        height++;
        free(line);
    }
    free(line);
    if (close(fd) == -1)
        error_message();
    return (height);
}

int get_width(char *file_name)
{
    int i;
    int width;
    int fd = 0;
    char *line;

    fd = open(file_name, fd);
    if (fd == -1)
        error_message();
    width = 0;
    get_next_line(fd, &line);
    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] != ' ' && line[i] != '-')
            width++;
        i++;
    }    
    free(line);
    if (close(fd) == -1)
        error_message();
    return (width);
}

void fill_matrix(int *matrix_line, char *line, map *map)
{
    char **nums;
    int i;
    int j;
    //printf("inside fill_matrix\n");
    
    nums = ft_split(line, ' ');
    for (int k = 0; k < map->width; k++)
        printf("%3s", nums[k]);
    printf("\n");
    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            matrix_line[j] = ft_atoi(&nums[i][j]);
            //printf("matrix line element = %d\n", matrix_line[i]);
            j++;
        }
        free(nums[i]);
        i++;
    }
    free(nums);
}

void read_file(char *file_name, map *map)
{
    int fd;
    char *line;
    int i;
    
    map->height = get_height(file_name);
    map->width = get_width(file_name);
    printf("inside read_file\n");
    map->matrix = (int **)malloc(sizeof(int*) * (map->height + 1));
    printf("1st malloc done\n");
    i = 0;
    while (i <= map->height) 
        map->matrix[i++] = (int*)malloc(sizeof(int) * (map->width + 1));
    printf("2st malloc done\n");
    fd = open(file_name, O_RDONLY);
    i = 0;
    while (get_next_line(fd, &line) > 0)
    {
        fill_matrix(map->matrix[i], line, map);
        free(line);
        i++;
    }
    close(fd);
    map->matrix[i] = NULL;
}
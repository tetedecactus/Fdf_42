/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:00:33 by olabrecq          #+#    #+#             */
/*   Updated: 2021/10/12 16:15:22 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void get_height_n_width(char *file_name, t_map *map)
{
    int fd;
    char *line;
    int old_width;

    old_width = 0;
    fd = open(file_name, O_RDONLY);
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
    close(fd);
    
}

void read_file(char *file_name, t_map *map)
{
    get_height_n_width(file_name, map);
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
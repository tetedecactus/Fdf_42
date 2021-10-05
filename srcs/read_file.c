/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:00:33 by olabrecq          #+#    #+#             */
/*   Updated: 2021/10/05 14:22:46 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void get_height_n_width(char *file_name, map *map)
{
    int fd;
    char *line;
    int i;
    int old_width;

    i = 0;
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

void read_file(char *file_name, map *map)
{
    get_height_n_width(file_name, map);
    printf("height = %d\n", map->height);
    printf("width = %d\n", map->width);

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:00:33 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/29 15:59:21 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int get_height(char *file_name)
{
    int height;
    int fd = 0;
    char *line;
    
    fd = open(file_name, fd);
    height = 0;
    while (get_next_line(fd, &line))
    {
        height++;
        free(line);
    }
    close(fd);
    return (height);
}

// int get_width(char *file_name)
// {
//     int i;
//     int width;
//     int fd = 0;
//     char *line;

//     fd = open(file_name, fd);
//     width = 0;
//     get_next_line(fd, &line);
//     i = 0;
//     while (line[i] != '\0')
//     {
//         if (line[i] == ft_itoa(ft_isnumber(i)));
//             width++;
//         i++;
//     }    
//     free(line);
//     close(fd);
//     return (width);
// }
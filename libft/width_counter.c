/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:05:32 by olabrecq          #+#    #+#             */
/*   Updated: 2021/10/14 14:42:39 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
* this function take line and delete all separator,
* it return the width of the line minus all the separator 
*/

#include "libft.h"

int width_counter(char *line, char separator)
{
    int i;
    int width;

    width = 0;
    i = 0;
    separator = ' ';
    while (line[i])
    {
        if (line[i] == '-')
            i++;
        if (line[i] != separator)
        {
            width++;
            i++;
        }
        i++;
    }
    return (width);
}

// int	main(int argc, char **argv)
// {
// 	// int i;
// 	// int j;
// 	fdf  **matrix;
	 
// 	matrix = NULL;
// 	matrix = alloc_and_height_fdf_map(argv[1]);

// 	if (argc != 2)
// 		error_message(2);
// 	read_n_create_map(argv[1], matrix);
// 	//print_matrix(matrix);
    
// 	free(matrix);
	
// 		//mlx_pixel_put(mlx_ptr, mlx_win_ptr, i++, 700, 0x00FF0000);
// 	return (0);
// }
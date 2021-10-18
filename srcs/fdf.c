/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:32:43 by olabrecq          #+#    #+#             */
/*   Updated: 2021/10/18 14:13:51 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//#include "../minilibx_macos/mlx_ptr.h"

void matrix_the_fifth_delallocated(t_map *map, t_point **matrix)
{
    int i;
    //int j;
    int height;
    //int width;
    
    height = map->height;
    //width = map->width;
    i = 0;
    while (i < height)
    {
        // j = 0;
        // while (j < width)
        // {
        //     free(matrix[i][j]);
        //     j++;
        
        free(matrix[i]);
        i++;
    }
    free(matrix);
}

void print_matrix(t_point **matrix, t_map *map)
{
    int i;
    int j;
	
    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            printf("%3.0f", matrix[i][j].z);
            j++;
        }
        printf("\n");
        i++;
    }
}

int	main(int argc, char **argv)
{
	t_map *map;
    t_point  **matrix;

	map = NULL;
	matrix = NULL;
	
	map = (t_map *)malloc(sizeof(t_map));
	if (argc != 2)
		error_message(2);
    get_height_n_width(argv[1], map);
    matrix = alloc_matrix(map);
    create_fdf_map(argv[1], matrix, map);
    print_matrix(matrix, map);
	//draw_matrix();
    //matrix_the_fifth_delallocated(map, matrix);
    //create_fdf_map(argv[1], matrix, map);
	//print_matrix(matrix, map);
	//read_n_create_map(argv[1], matrix);
	//free(map);
	
		//mlx_pixel_put(mlx_ptr, mlx_win_ptr, i++, 700, 0x00FF0000);
	return (0);
}

// gcc *.c -lmlx -framework OpenGL -framework AppKit && ./a.out
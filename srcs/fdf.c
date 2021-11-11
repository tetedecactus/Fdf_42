/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:32:43 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/11 11:33:04 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void matrix_the_fifth_delallocated(fdf *data)
{
    int i;
    //int j;
    int height;
    
    height = data->map_height;
    i = 0;
    while (i < height)
    {
        // j = 0;
        // while (j < data->map_width[i])
        // {
        //     free(&data->matrix[i][j]);
        //     free(&data->map_width[i]);
        //     j++;
        // }
        free(data->matrix[i]);
        i++;
    }
    free(data->matrix);
}


void print_matrix(fdf *data)
{
    int i;
    int j;
    
	
    i = 0;
    while (i < data->map_height)
    {
        j = 0;
        while (j < data->map_width[i])
        {
            printf("%3.0f", data->matrix[i][j].z);
            j++;
        }
        printf("\n");
        i++;
    }
}

void print_h_w(fdf *data)
{
    int i = 0;
    while (i != (data->map_height))
    {
        printf(" witdh[%d] = %d\n", i, data->map_width[i]);
        i++;
    }
    printf("height = %d\n", data->map_height);
}

int	main(int argc, char **argv)
{
	fdf *data;

    data = NULL;
	data = (fdf *)malloc(sizeof(fdf));
	if (argc != 2)
		error_message(2);
    get_height_n_width(argv[1], data);
    print_h_w(data);
    //printf("height: %d width: %d\n", data->map_height, data->map_width[0]);
    data->matrix = alloc_matrix(data);
    data->matrix = create_fdf_matrix(argv[1], data);
    print_matrix(data);
	draw_matrix(data);
    matrix_the_fifth_delallocated(data);
    free(data);
	
	return (0);
}


// -----> Liste de truc a faire
//        1. Arrenger pour que toute les maps fonctionnes
//        2. Bonus


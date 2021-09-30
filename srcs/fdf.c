/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:32:43 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/30 15:25:26 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//#include "../minilibx_macos/mlx_ptr.h"

int	main(int argc, char **argv)
{
	char *file_name;
	map map;
	
	
	file_name = argv[1];
	map.width = 0;
	map.height = 0;
	if (argc == 2)
	{
    	map.height = get_height(file_name);
		map.width = get_width(file_name);	
	}
    printf("height = %d\n", map.height);
    printf("width = %d\n", map.width);
	
		//mlx_pixel_put(mlx_ptr, mlx_win_ptr, i++, 700, 0x00FF0000);
	return 0;
}

// gcc *.c -lmlx -framework OpenGL -framework AppKit && ./a.out
	//int i = 100;
	// void	*mlx_ptr;
	// void	*mlx_win_ptr;
	// t_data	img;

	// mlx_ptr = mlx_init();
	// mlx_win_ptr = mlx_new_window(mlx_ptr, WIDTH, HIGH, "FDF FUCKERRRR");
	// img.img = mlx_new_image(mlx_ptr, WIDTH, HIGH);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 500, 700, 0x00FF0000);
	// mlx_put_image_to_window(mlx_ptr, mlx_win_ptr, img.img, 0, 0);
	// mlx_loop(mlx_ptr);
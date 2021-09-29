/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:32:43 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/29 16:01:55 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//#include "../minilibx_macos/mlx_ptr.h"

int	main(void)
{
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

	int height = 0;

    height = get_height("./test_maps/42.fdf");
    printf("%d\n", height);

		//mlx_pixel_put(mlx_ptr, mlx_win_ptr, i++, 700, 0x00FF0000);
	
}

// gcc *.c -lmlx -framework OpenGL -framework AppKit && ./a.out
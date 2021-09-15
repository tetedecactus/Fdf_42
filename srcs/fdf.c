/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:32:43 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/15 12:19:15 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//#include "../minilibx_macos/mlx.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	img;
	int 	i;

	i = 100;
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, WIDTH, HIGH, "FDF U FAT CUNT");
	//while (i <= 700)
		//mlx_pixel_put(mlx_ptr, mlx_win, i++, 700, 0x00FF0000);
	img.img = mlx_new_image(mlx_ptr, WIDTH, HIGH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//mlx_pixel_put(&img, mlx_win, 100, 700, 0x00FF0000);
	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 700, 990);
	
	mlx_loop(mlx_ptr);
}

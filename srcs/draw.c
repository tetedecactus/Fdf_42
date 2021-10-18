/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:05:37 by olabrecq          #+#    #+#             */
/*   Updated: 2021/10/18 14:39:53 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

void	my_mlx_pixel_put(fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_matrix(void)
{
	void	*mlx_ptr;
	void	*mlx_win_ptr;
	fdf	    img;

	mlx_ptr = mlx_init();
	mlx_win_ptr = mlx_new_window(mlx_ptr, WIDTH, HIGH, "FDF FUCKERRRR");
	img.img = mlx_new_image(mlx_ptr, WIDTH, HIGH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 450, 300, WHITE);
	mlx_put_image_to_window(mlx_ptr, mlx_win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}

int main()
{
	draw_matrix();
	return (0);
}
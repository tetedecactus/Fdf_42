/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:27:30 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/11 11:32:58 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdbool.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include <mlx.h>
# include "../libft/libft.h"
// # include "../minilibx_macos/mlx.h"

# define WIDTH 1920
# define HEIGHT 1080
# define WIDTH_IMG (WIDTH / 3)
# define HEIGHT_IMG (HEIGHT / 3)
# define MYSTERE 0x830707
# define RED 0x00ff0000
# define WHITE 0x00ffffff
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

typedef struct s_point
{
	float  		x;
	float 		y;
	float 		z;
	float 		row;
	float 		col;
	int 		color;
	//bool 		is_hexa;
	//t_point 	**matrix;	
} t_point;


typedef struct fdf 
{
	t_point 	**matrix;
	
	int 		*map_width;
	int 		map_height;
	
	void 	*mlx_ptr;
	void 	*win_ptr;
	
	float 	rotation_cos;
	float 	rotation_sin;
	float	shift_x;
	float 	shift_y;
	int 	projection;
	int 	zoom;
	float 	color;
}	fdf;

	// void	*img;
	// char	*addr;
	// int		bits_per_pixel;
	// int		line_length;
	// int		endian;
	// // float 	x;
	// // float 	y;
	// // float 	x1;
	// // float 	y1;

// MiniLibX function
void	my_mlx_pixel_put(fdf *data, int x, int y, int color);

// Read fucntion
void    get_height_n_width(char *file_name, fdf *data);
t_point **create_fdf_matrix(char *file_name, fdf *data);
t_point	**alloc_matrix(fdf *data);

// void 	read_n_create_map(char *file_name, t_map *map);
// init function 
void 	init_map(fdf *data, int line_width);
void    init_matrix(t_point *parameters);
void 	init_data(fdf *data);
//void 	init_width(fdf *data, int line_width);

// Draw function
void 	draw_matrix(fdf *data);
// void 	draw(fdf *data, t_map *map_info, t_point **matrix);

// Key touch function
int 	del_key(int key, fdf *data);


#endif
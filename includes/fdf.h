/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:27:30 by olabrecq          #+#    #+#             */
/*   Updated: 2021/10/26 09:58:01 by olabrecq         ###   ########.fr       */
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

typedef struct s_point
{
	float  	x;
	float 	y;
	float 	z;
	float 	row;
	float 	col;
	int 	color;
	bool 	is_hexa;	
} t_point;

typedef struct s_map
{
	int width;
	int height;
	t_point point;	
	
} t_map;

typedef struct	fdf 
{
	float 	color;
	void 	*mlx_ptr;
	void 	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	zoom;
	t_point **point;
	t_map 	map;
	
}				fdf;

// MiniLibX function
void	my_mlx_pixel_put(fdf *data, int x, int y, int color);

// Read fucntion
void    get_height_n_width(char *file_name, t_map *map);
t_point **create_fdf_matrix(char *file_name, t_point **matrix, t_map *map);
t_point	**alloc_matrix(t_map *map);

// void 	read_n_create_map(char *file_name, t_map *map);
// init function 
void 	init_map(t_map *map);
void    init_matrix(t_point *parameters);

// Draw function
void 	draw_matrix(t_map *map_info, t_point **matrix);
void 	draw(fdf *data, t_map *map_info, t_point **matrix);

#endif
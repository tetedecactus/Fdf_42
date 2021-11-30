/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:27:30 by olabrecq          #+#    #+#             */
/*   Updated: 2021/11/20 11:22:21 by olabrecq         ###   ########.fr       */
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
# define WIDTH_IMG 5760
# define HEIGHT_IMG 3240
# define RED 0xff0000
# define WHITE 0xffffff
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ZOOM_OUT 37
# define ZOOM_IN 46

typedef struct s_point
{
	float			x;
	float			y;
	float			z;
}	t_point;

typedef struct s_map
{
	int				*map_width;
	int				map_height;
}	t_map;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*addr;
	void			*img;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_mlx;

typedef struct s_move
{
	float			rotation_cos;
	float			rotation_sin;
	float			shift_x;
	float			shift_y;
	int				projection;
	int				zoom;
	unsigned int	color;
	float			x_step;
	float			y_step;
	int				max;
	int				z;
	int				z1;
}	t_move;

typedef struct t_fdf
{
	t_point			**matrix;
	t_map			info;
	t_mlx			mlx;
	t_move			move;
}	t_fdf;

// MiniLibX function
void			my_mlx_pixel_put(t_fdf *data, unsigned int x, unsigned int y,
					unsigned int color);

// Read fucntion
void			get_height_n_width(char *file_name, t_fdf *data);
t_point			**create_fdf_matrix(char *file_name, t_fdf *data);
t_point			**alloc_matrix(t_fdf *data);

// void 	read_n_create_map(char *file_name, t_map *map);
// init function 
void			init_map(t_fdf *data, int line_width);
void			init_matrix(t_point *parameters);
void			init_data(t_fdf *data);

// Draw function
void			draw_matrix(t_fdf *data);
void			draw(t_fdf *data);

// Draw extension  function
float			mod(float i);

// void isometric(float *x, float *y, int z, t_fdf *data);
void			isometric(float *x, float *y, int z, t_fdf *data);
void			clear_image(char *addr);

// Key touch function
int				check_key(int key, t_fdf *data);

// set function
unsigned int	set_color(int z, int z1);
void			set_zoom(t_fdf *data);
void			set_z(float x1, float y1, t_fdf *data);
void			set_z1(float x1, float y1, t_fdf *data);

#endif
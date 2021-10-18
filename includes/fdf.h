/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:27:30 by olabrecq          #+#    #+#             */
/*   Updated: 2021/10/15 12:35:33 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

# define WIDTH 1920
# define HIGH 1080

typedef struct s_point
{
	float  	x;
	float 	y;
	float 	z;
	float 	color;
	float 	row;
	float 	col;	
} t_point;

typedef struct s_map
{
	int width;
	int height;
	t_point point;	
} t_map;

typedef struct	fdf 
{
	/*
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	void 	*mlx_ptr;
	void 	*mlw_win_ptr;
*/
	t_point point;
	t_map 	map;
}				fdf;

// MiniLibX function
//void	my_mlx_pixel_put(fdf *data, int x, int y, int color);

// Read fucntion
void 	read_n_create_map(char *file_name, t_map *map);
void 	print_matrix(t_point **matrix, t_map *map);
void 	get_height_n_width(char *file_name, t_map *map);
void    init_matrix(t_point *parameters);
//void 	print_matrix(fdf **matrix);
t_point	**create_fdf_map(char *file_name, t_point **matrix, t_map *map);


#endif
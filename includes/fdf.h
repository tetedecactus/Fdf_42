/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:27:30 by olabrecq          #+#    #+#             */
/*   Updated: 2021/10/13 13:30:42 by olabrecq         ###   ########.fr       */
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

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point
{
	float 	x;
	float 	y;
	float 	z;
	int 	color;
	int 	row;
	int 	col;	
} t_point;

typedef struct s_map
{
	int 	height;
	int 	width;
	t_point *point;
} t_map;

// MiniLibX function
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// Read fucntion
void 	read_file(char *file_name, t_map *map);

#endif
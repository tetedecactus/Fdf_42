# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 13:03:04 by olabrecq          #+#    #+#              #
#    Updated: 2021/11/22 08:30:29 by olabrecq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit

NAME = fdf

SRCS = 	./srcs/fdf.c \
		./srcs/read_file.c \
		./srcs/draw.c \
		./srcs/init.c \
		./srcs/key_touch.c \
		./srcs/draw_extension.c \
		./srcs/set_function.c \
		
INCLUDES = libft/libft.a minilibx_macos/libmlx.a

OBJS = ${SRCS:.c=.o}

HEADER	= includes/fdf.h 

CC = gcc 

CFLAGS = -g -Imlx -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	    @make -C libft/
		@make -C minilibx_macos/
		${CC} ${CFLAGS} ${INCLUDES} ${FRAMEWORKS} ${OBJS}  -o ${NAME} 

clean: 
		rm -f ${OBJS}
		@make -C libft/ clean
		@make -C minilibx_macos/ clean 
fclean: clean
		rm -f ${NAME}
		@make -C libft/ fclean

re: fclean all

.PHONY: clean fclean re all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 13:03:04 by olabrecq          #+#    #+#              #
#    Updated: 2021/10/15 11:12:32 by olabrecq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#FRAMEWORKS = -framework OpenGL -framework AppKit

NAME = fdf

SRCS = 	./srcs/fdf.c \
		./srcs/read_file.c \
		./srcs/minilibx_function.c \

INCLUDES = ./libft/libft.a ./minilibx_macos/libmlx.a

OBJS = ${SRCS:.c=.o}

HEADER	= ./includes/fdf.h

CC = gcc 

CFLAGS = -g -Wall -Wextra -Werror

all: ${NAME}

${NAME}:${OBJS}
	    @make -C ./libft/
		@make -C ./minilibx_macos/
		@${CC} ${CFLAGS} ${OBJS}  -o ${NAME} ${INCLUDES} 

clean: 
		rm -f ${OBJS} 
		@make clean -C ./libft/
		@make clean -C ./minilibx_macos/
fclean: clean
		rm -f ${NAME}
		@make fclean -C ./libft/

re: fclean all

.PHONY: clean fclean re all

# ent re cflags et OBJS ${FRAMEWORKS}
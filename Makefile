# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 13:03:04 by olabrecq          #+#    #+#              #
#    Updated: 2021/10/19 11:27:12 by olabrecq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit

NAME = fdf

SRCS = 	./srcs/fdf.c \
		./srcs/read_file.c \
		./srcs/draw.c \

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

# # # entre cflags et OBJS ${FRAMEWORKS}

# FRAMEWORKS=-framework OpenGL -framework AppKit
# FLAGS=-Werror -Wextra -Wall -lmlx
# NAME=fdf
# SRC=./srcs/fdf.c \
# 	./srcs/read_file.c \
#  	./srcs/minilibx_function.c \
#  	./srcs/draw.c \
# INCLUDES=libft/libft.a minilibx_macos/libmlx.a

# all: $(NAME)

# $(NAME): $(OBJ)
# 	@make -C libft/
# 	@make -C minilibx_macos/
# 	gcc -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

# clean:
# 	@make -C libft/ clean
# 	@make -C minilibx_macos/ clean

# fclean: clean
# 	/bin/rm -f $(NAME)
# 	@make -C libft/ fclean

# re: fclean all
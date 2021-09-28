# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 13:03:04 by olabrecq          #+#    #+#              #
#    Updated: 2021/09/28 09:24:04 by olabrecq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fdf

SRCS = 	./srcs/fdf.c \
		./srcs/minilibx_function.c 

OBJS = ${SRCS:.c=.o}
HEADER	= ./includes/fdf.h
CC = gcc 
FLAGS = -g -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o} 

all: ${NAME}

${NAME}:${OBJS}
		@${CC} ${OBJS} ${FLAGS} -o ${NAME}

clean: 
		rm -f ${OBJS}
fclean: clean
		rm -f ${NAME}
re: fclean all

.PHONY: clean fclean re all

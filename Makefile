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

NAME = fdf

SRC 		= 	srcs
OBJ 		= 	obj
INC 		= 	includes

LIB 		=	lib
LIBFT		=	$(LIB)/libft
MLX_LINUX	= 	$(LIB)/minilibx_linux
MLX_MAC		= 	$(LIB)/minilibx_mac

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -g

RM			=	rm -rf
MK			=	mkdir
NM			=	norminette

MAKE_DIR	= $(MAKE) --no-print-directory -C

CFILES 		= 	fdf.c \
				read_file.c \
				draw.c \
				init.c \
				key_touch.c \
				draw_extension.c \
				set_function.c \

INCLUDES 	= lib/libft/libft.h /home/olabrecq/projet42/fdf/lib/minilibx_linux/mlx.h

HFILES		= fdf.h

OFILES 		= $(CFILES:.c=.o)

SRCS		=	$(addprefix $(SRC)/, $(CFILES))
HEADERS		=	$(addprefix $(INC)/, $(HFILES))
OBJS		=	$(addprefix $(OBJ)/, $(OFILES))

FRAMEWORKS 			= -lmlx -framework OpenGL -framework AppKit
FRAMEWORKS_LINUX 	= -lft -lmlx -lm -lXext -lbsd -lX11

$(OBJ)/%.o:	$(SRC)/%.c
			$(CC) $(CFLAGS) -I$(INC) -I$(LIB) -c $< -o $@

all: 		$(NAME)

$(NAME): 	$(OBJ) $(OBJS)
			@$(MAKE_DIR) $(LIBFT)
			@$(MAKE_DIR) $(MLX_MAC)
			$(CC) $(INCLUDES) $(FRAMEWORKS) $(OBJS)  -o $(NAME)
$(OBJ):
			@$(MK) $(OBJ)

linux:	$(OBJ) $(OBJS)
		@$(MAKE_DIR) $(LIBFT)
		@$(MAKE_DIR) $(MLX_LINUX)
		$(CC) $(OBJS) -L$(LIBFT) -L$(MLX_LINUX) $(FRAMEWORKS_LINUX) -o $(NAME)

clean:
		@$(MAKE_DIR) $(LIBFT) clean
		@$(MAKE_DIR) $(MLX_LINUX) clean
		@$(RM) $(OBJS)
		@$(RM) $(OBJ)

fclean: clean
		@$(MAKE_DIR) $(LIBFT) fclean
		@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all

# -------------------------------------------------------------

# FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit
# FRAMEWORKS_LINUX 	= -lft -lmlx -lm -lXext -lbsd -lX11

# NAME = fdf

# SRCS = 	./srcs/fdf.c \
# 		./srcs/read_file.c \
# 		./srcs/draw.c \
# 		./srcs/init.c \
# 		./srcs/key_touch.c \
# 		./srcs/draw_extension.c \
# 		./srcs/set_function.c \
		
# INCLUDES = /lib/libft/libft.a /lib/minilibx_linux/libmlx.a

# OBJS = ${SRCS:.c=.o}

# HEADER	= includes/fdf.h 

# CC = gcc 

# CFLAGS = -g -Imlx -Wall -Wextra -Werror

# all: ${NAME}

# ${NAME}: ${OBJS}
# 	    @make -C /lib/libft/
# 		@make -C minilibx_macos/
# 		${CC} ${CFLAGS} ${INCLUDES} ${FRAMEWORKS_LINUX} ${OBJS}  -o ${NAME} 

# clean: 
# 		rm -f ${OBJS}
# 		@make -C /lib/libft/ clean
# 		@make -C minilibx_macos/ clean 
# fclean: clean
# 		rm -f ${NAME}
# 		@make -C libft/ fclean

# re: fclean all

# .PHONY: clean fclean re all
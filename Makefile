# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcherrie <hcherrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 20:49:48 by hcherrie          #+#    #+#              #
#    Updated: 2021/05/08 02:58:31 by hcherrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
NAME			= cub3D
HEADER			= ./include/cub3d.h
MLX_LIB_NAME	= libmlx.dylib
DEBUG_DIR		= a.out.dSYM
DEBUG_EXEC		= a.out
MLX_DIR			= mlx
LIB_DIR 		= ./srcs/libft
LIB_NAME		= libft.a
OPENGL			= -framework OpenGL
APPKIT			= -framework AppKit
SRC_PATH		= ./include srcs srsc/r_cast srcs/parser /srcs/libft
SRC_LIST		= $(wildcard $(dir)/*.c)
SRC				= $(foreach dir, $(SRC_PATH), $(SRC_LIST))
PROJ_OBJS		= $(SRC:.c=.o)
RM				= rm
TMP_SWP			= .swp
TMP_GCH			= .gch
SNAPSHOT		= snapshot.bmp
RED				="\033[0;31m"
GREEN			="\033[0;32m"
NC				="\033[0m"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: makelibft makemlx $(NAME)

makelibft:
		@cd $(LIB_DIR) && make
		@echo $(GREEN)$(LIB_NAME) created $(NC)

makemlx:
		@cd $(MLX_DIR) && make
		@echo $(GREEN)$(MLX_LIB_NAME) created $(NC)
		@cd $(MLX_DIR) && cp $(MLX_LIB_NAME) ../$(MLX_LIB_NAME)
		@echo $(GREEN)$(MLX_LIB_NAME) copied to the exec path $(NC)

$(NAME): $(PROJ_OBJS) $(HEADER)
		@$(CC) $(CFLAGS) $(PROJ_OBJS) $(LIB_DIR)/$(LIB_NAME) \
		$(MLX_LIB_NAME) $(OPENGL) $(APPKIT) -o $(NAME)
		@echo $(GREEN) cub3D is ready, run it with map and enjoy or create screenshot with second arg \"--save\" $(NC)

clean:
		@$(RM) -f $(PROJ_OBJS) $(wildcard *$(TMP_SWP)) $(wildcard *$(TMP_GCH))
		@cd $(LIB_DIR) && make clean
		@cd $(MLX_DIR) && make clean
		@echo $(RED) obj deletet $(NAME) $(NC)

fclean:	clean
		@$(RM) $(NAME) $(MLX_LIB_NAME)
		@cd $(LIB_DIR) && make fclean
		@echo $(RED) all deleted $(NC)

re:		fclean all

.PHONY:		all clean fclean re

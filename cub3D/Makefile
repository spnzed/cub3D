# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 19:41:29 by erosas-c          #+#    #+#              #
#    Updated: 2024/06/17 20:23:51 by erosas-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Variables -------------------------------------------------------------- #

CC				=		gcc
HEADER_NAME		=		cub3d.h
LIBMLX_NAME		=		libmlx.a
LIBFT_NAME		=		libft.a
NAME			=		cub3d

# --- Compiler flags --------------------------------------------------------- #

CFLAGS			=		-MMD -Wall -Wextra -Werror -g #-fsanitize='leak'
LIBMLX_FLAGS	=		-lmlx -lX11 -lXext -lm -lbsd

# --- Directories ------------------------------------------------------------ #

LIBMLX_DIR		=		lib/minilibx-linux/
LIBFT_DIR		=		lib/libft_gnl/
INC_DIR			=		inc/
SRC_DIR			=		src/
OBJ_DIR			=		obj/
DEP_DIR			= 		$(OBJ_DIR)

# --- Includes --------------------------------------------------------------- #

INCLUDES		=		-I $(INC_DIR) -I $(LIBFT_DIR) -I $(LIBMLX_DIR)
LIB_INCLUDE		=		-L $(LIBFT_DIR) -lft -L $(LIBMLX_DIR) $(LIBMLX_FLAGS)

# --- Files ------------------------------------------------------------------ #

OBJ_FILES 		= 		$(SRC_FILES:.c=.o)
DEP_FILES 		= 		$(SRC_FILES:.c=.d)
SRC_FILES	=	arguments.c			big_map2d.c			check_map.c			check_parameters.c 	\
				create_image.c		draw_line.c			errors.c			get_color.c			\
				get_file.c			h_linescross.c		handle_map.c		loop_functions.c	\
				main.c				map_to_file.c 		minimap.c			move_arrows.c		\
				move.c				orientation.c		put_images.c		ray_casting.c		\
				render.c 			utils.c				utils2.c			wall.c	

# --- Files full paths ------------------------------------------------------- #

LIBFT_PATH		= 		$(addprefix $(LIBFT_DIR), $(LIBFT_NAME))
LIBMLX_PATH		= 		$(addprefix $(LIBMLX_DIR), $(LIBMLX_NAME))
OBJ_PATH		=		$(addprefix $(OBJ_DIR), $(OBJ_FILES))
DEP_PATH		=		$(addprefix $(DEP_DIR), $(DEP_FILES))

# --- Compilation rules ------------------------------------------------------ #

all:
		mkdir -p $(OBJ_DIR)
		$(MAKE) -C $(LIBFT_DIR)
		$(MAKE) -C $(LIBMLX_DIR)
		$(MAKE) $(NAME)

$(NAME): $(OBJ_PATH) $(LIBMLX_PATH) Makefile
	$(CC) $(CFLAGS)  $(INCLUDES) $(OBJ_PATH) -o $@ $(LIB_INCLUDE)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

-include $(DEP_PATH)

# --- Cleaning rules --------------------------------------------------------- #

clean:	
			rm -f $(OBJ_PATH) $(DEP_PATH)
			rm -rf $(OBJ_DIR)c
			$(MAKE) -C $(LIBFT_DIR) clean
			$(MAKE) -C $(LIBMLX_DIR) clean

fclean:		clean
			rm -f $(NAME)
			$(MAKE) -C $(LIBFT_DIR) fclean
			$(MAKE) -C $(LIBMLX_DIR) clean

re:			fclean all

.PHONY:		all clean fclean re
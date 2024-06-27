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

CC				=	gcc
HEADER_NAME		=	cub3d.h
LIBMLX_NAME		=	libmlx.a
LIBFT_NAME		=	libft.a
NAME			=	cub3d

# --- Compiler flags --------------------------------------------------------- #

CFLAGS			=	-MMD -Wall -Wextra -Werror -g
LIBMLX_FLAGS	=	-lmlx -lX11 -lXext -lm -lbsd

# --- Directories ------------------------------------------------------------ #

LIBMLX_DIR		=	lib/minilibx-linux/
LIBFT_DIR		=	lib/libft_gnl/
INC_DIR			=	inc/
SRC_DIR			=	src/
OBJ_DIR			=	obj/
DEP_DIR			= 	$(OBJ_DIR)

# --- Bonus --------------------------------------------------------------- #

NAME_BONUS		=	cub3d_bonus
OBJ_DIR_BONUS	=	obj_bonus/
SRC_DIR_BONUS	=	src_bonus/
OBJ_PATH_BONUS	=	$(addprefix $(OBJ_DIR_BONUS), $(OBJ_FILES_BONUS))
DEP_PATH_BONUS	=	$(addprefix $(DEP_DIR_BONUS), $(DEP_FILES_BONUS))
OBJ_FILES_BONUS	= 	$(SRC_FILES_BONUS:.c=.o)
DEP_FILES_BONUS	= 	$(SRC_FILES_BONUS:.c=.d)
SRC_FILES_BONUS	=	arguments.c			check_map.c			check_parameters.c 	create_image.c		\
					draw_line.c			errors.c			get_color.c			get_file.c			\
					h_linescross.c		handle_map.c		loop_functions.c	main.c				\
					map_to_file.c 		minimap.c			move_arrows.c		move.c				\
					orientation.c		put_images.c		ray_casting.c		render.c 			\
					utils.c				utils2.c			wall.c

# --- Includes --------------------------------------------------------------- #

INCLUDES		=	-I $(INC_DIR) -I $(LIBFT_DIR) -I $(LIBMLX_DIR)
LIB_INCLUDE		=	-L $(LIBFT_DIR) -lft -L $(LIBMLX_DIR) $(LIBMLX_FLAGS)

# --- Files ------------------------------------------------------------------ #

OBJ_FILES 		= 	$(SRC_FILES:.c=.o)
DEP_FILES 		= 	$(SRC_FILES:.c=.d)
SRC_FILES		=	arguments.c			check_map.c			check_parameters.c 	create_image.c		\
					draw_line.c			errors.c			get_color.c			get_file.c			\
					h_linescross.c		handle_map.c		loop_functions.c	main.c				\
					map_to_file.c 		move_arrows.c		move.c				orientation.c		\
					put_images.c		ray_casting.c		render.c 			utils.c				\
					utils2.c			wall.c

# --- Files full paths ------------------------------------------------------- #

LIBFT_PATH		= 	$(addprefix $(LIBFT_DIR), $(LIBFT_NAME))
LIBMLX_PATH		= 	$(addprefix $(LIBMLX_DIR), $(LIBMLX_NAME))
OBJ_PATH		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
DEP_PATH		=	$(addprefix $(DEP_DIR), $(DEP_FILES))

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

bonus: 
		mkdir -p $(OBJ_DIR_BONUS)
		$(MAKE) -C $(LIBFT_DIR)
		$(MAKE) -C $(LIBMLX_DIR)
		$(MAKE) $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_PATH_BONUS) $(LIBMLX_PATH) Makefile
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_PATH_BONUS) -o $@ $(LIB_INCLUDE)

$(OBJ_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c | $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

-include $(DEP_PATH_BONUS)

# --- Cleaning rules --------------------------------------------------------- #

clean:	
			rm -f $(OBJ_PATH) $(DEP_PATH)
			rm -rf $(OBJ_DIR)c
			rm -f $(OBJ_PATH_BONUS) $(DEP_PATH_BONUS)
			rm -rf $(OBJ_DIR_BONUS)c
			$(MAKE) -C $(LIBFT_DIR) clean
			$(MAKE) -C $(LIBMLX_DIR) clean

fclean:		clean
			rm -f $(NAME)
			rm -f $(NAME_BONUS)
			$(MAKE) -C $(LIBFT_DIR) fclean
			$(MAKE) -C $(LIBMLX_DIR) clean

re:			fclean all

.PHONY:		all clean fclean re
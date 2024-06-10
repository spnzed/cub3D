# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/04 17:25:20 by erosas-c          #+#    #+#              #
#    Updated: 2024/05/23 19:54:22 by erosas-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
HEADER		=	inc/

SRC_DIR		=	src/

INC_DIR		=	inc
SRC_FILES	=	arguments.c			big_map2d.c			check_map.c			check_parameters.c 	\
				create_image.c		draw_line.c			errors.c			get_color.c			\
				get_file.c			handle_map.c 		h_linescross.c		loop_functions.c	\
				main.c				map_to_file.c 		minimap.c			move_arrows.c		\
				move.c				orientation.c		put_images.c		put_position.c 		\
				ray_casting.c		ray_end.c			render.c 			utils.c				\
				utils2.c			wall.c				window2.c								\
					
OBJ_DIR		=	obj/
OBJ_FILES	=	$(SRC_FILES:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

DEP_FILES	=	$(SRC_FILES:.c=.d)
DEPS		=	$(addprefix $(OBJ_DIR), $(DEP_FILES))

LIBFT_DIR	=	lib/libft_gnl
LIBFT		=	$(LIBFT_DIR)/libft.a

MLX_DIR		=	lib/mlx
MLX 		= 	$(MLX_DIR)/libmlx.a

INCLUDE		=	-I $(INC_DIR) -I $(LIBFT_DIR)/inc -I $(MLX_DIR)
FRAMES 		= 	-framework OpenGL -framework AppKit 

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -MMD #-fsanitize='address' -g
CLEAN_CAR	=	\033[2K\r

RM			=	rm -rf

######################################################################

all: make_libs $(NAME)

make_libs:
	@make -C lib/libft_gnl/
#	@echo "$(CLEAN_CAR)$(OK_COLOR)Starting compilation of Minilibx...$(NO_COLOR)"
	@$(MAKE) -C lib/mlx 2> ERRORS
#	@echo "$(CLEAN_CAR)$(OK_COLOR)Minilibx compiled!$(NO_COLOR)"
	@rm ERRORS

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx $(FRAMES) $(OBJS) -o $@
	@sleep 0.2
	@echo "$(CLEAN_CAR)$(OK_COLOR)Cub3D compiled!$(NO_COLOR)"
	@echo "Use $(BLUE_COLOR)./cub3D$(NO_COLOR) to launch the program"

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $@

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -g -c $< -o $@
	@printf "$(CLEAN_CAR)$(OK_COLOR)[Compiling cub3D]$(BLUE_COLOR) : $(WARN_COLOR)$<$(NO_COLOR)\r"

clean:
	@make -C lib/libft_gnl/ clean
	@make -C lib/mlx/ clean
	@$(RM) $(OBJ_DIR)
	@echo "$(ERROR_COLOR)Dependencies and objects removed$(NO_COLOR)"

fclean: clean
	@make -C lib/libft_gnl/ fclean
	@$(RM) $(NAME)
	@echo "$(ERROR_COLOR)$(NAME) removed$(NO_COLOR)"

re: fclean all

-include $(DEPS)

.PHONY: all libft clean fclean re

NO_COLOR		=	\x1b[0m
OK_COLOR		=	\x1b[32;01m
ERROR_COLOR		=	\x1b[31;01m
WARN_COLOR		=	\x1b[33;01m
BLUE_COLOR		=	\x1b[34;01m

OK_STRING		=	$(OK_COLOR)[OK]$(NO_COLOR)
ERROR_STRING	=	$(ERROR_COLOR)[ERRORS]$(NO_COLOR)
WARN_STRING		=	$(WARN_COLOR)[WARNINGS]$(NO_COLOR)

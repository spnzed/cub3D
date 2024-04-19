# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/04 17:25:20 by erosas-c          #+#    #+#              #
#    Updated: 2024/04/19 18:08:25 by erosas-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

SRC_DIR		=	src/

INC_DIR		=	inc/
SRC_FILES	=	main.c		window.c
					
OBJ_DIR		=	obj/
OBJ_FILES	=	$(SRC_FILES:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

DEP_FILES	=	$(SRC_FILES:.c=.d)
DEPS		=	$(addprefix $(OBJ_DIR), $(DEP_FILES))

LIBFT		=	lib/libft_gnl/libft.a
MLX			=	lib/mlx/libmlx.a

INCLUDE		=	-I inc/ -I lib/libft_gnl/ -I lib/mlx/ -lmlx
#FRAMES		= 	-framework OpenGL -framework AppKit 

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -MMD
CLEAN_CAR	=	\033[2K\r

RM			=	rm -rf

######################################################################

all: make_libs $(NAME)

make_libs:
	@make -C lib/libft_gnl/
	@make -C lib/mlx/ 2> ERRORS
	@rm ERRORS

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -L lib/libft_gnl/ -L lib/mlx/ -lmlx -lft $(OBJS) -o $@
	@sleep 0.2
	@echo "$(CLEAN_CAR)$(OK_COLOR)Cub3D compiled!$(NO_COLOR)"
	@echo "Use $(BLUE_COLOR)./cub3D$(NO_COLOR) to launch the program"

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(LIBFT) $(MLX) Makefile
	@$(CC) $(CFLAGS) $(INCLUDE) -g -c $< -o $@
	@printf "$(CLEAN_CAR)$(OK_COLOR)[Compiling cub3D]$(BLUE_COLOR) : $(WARN_COLOR)$<$(NO_COLOR)\r"

clean_libs:
	@make -C lib/libft_gnl/ clean
	@make -C lib/mlx/ clean

clean: clean_libs
	@$(RM) $(OBJS) $(DEPS)
	@echo "$(ERROR_COLOR)Dependencies and objects removed$(NO_COLOR)"

fclean: clean
	@make -C lib/libft_gnl/ fclean
	@$(RM) $(NAME)
	@$(RM) $(OBJ_DIR)
	@echo "$(ERROR_COLOR)$(NAME) removed$(NO_COLOR)"

re: fclean all

-include $(DEPS)

.PHONY: all make_libs clean_libs clean fclean re

NO_COLOR		=	\x1b[0m
OK_COLOR		=	\x1b[32;01m
ERROR_COLOR		=	\x1b[31;01m
WARN_COLOR		=	\x1b[33;01m
BLUE_COLOR		=	\x1b[34;01m

OK_STRING		=	$(OK_COLOR)[OK]$(NO_COLOR)
ERROR_STRING	=	$(ERROR_COLOR)[ERRORS]$(NO_COLOR)
WARN_STRING		=	$(WARN_COLOR)[WARNINGS]$(NO_COLOR)
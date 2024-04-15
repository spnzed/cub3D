# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 18:30:42 by erosas-c          #+#    #+#              #
#    Updated: 2024/04/15 20:57:05 by erosas-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################´

NAME		=	cub3D

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -MMD
CLEAN_CAR	=	\033[2K\r

RM			=	rm -rf
MD			=	mkdir -p
CP			=	cp -f

################################################################################
#                             PROGRAM'S DIR + FILES                            #
################################################################################

SRC_DIR			=	src/
INC_DIR			=	include/
OBJ_DIR			=	obj/
LIBFT_DIR		=	lib/libft/

INCLUDE			+=	-I $(INC_DIR) -I $(LIBFT_DIR)

vpath %.c $(SRC_DIR)
SRC_FILES		=	main.c

SRC				+=	$(ADDPREFIX $(SRC_DIR), $(SRC_FILES))
OBJS			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS			+=	$(addsuffix .d, $(basename $(OBJS)))
LIBFT			=	lib/libft/libft.a


################################################################################
#                                     MAKEFILE                                 #
################################################################################

$(OBJ_DIR)%.o : %.c Makefile 
	mkdir $@
	@make -sC $(LIBFT_DIR)
	@printf "$(CLEAN_CAR)$(OK_COLOR)[Compiling cub3D]$(BLUE_COLOR) : $(WARN_COLOR)$<$(NO_COLOR)"

	@$(CC) -MT $@ -MMD -MP -c $(CFLAGS) -I$(RFLAGS) -Iinclude/ $(INCLUDE) $< -o $@

all:		libft $(NAME) 

libft:	
			@make -sC $(LIBFT_DIR)

$(NAME):	$(OBJS) 
			@$(CC) $(CFLAGS) -L $(LIBFT_DIR) $(OBJS) -lft -o $@
			@sleep 0.2
			@echo "$(CLEAN_CAR)$(OK_COLOR)Cub3D compiled!$(NO_COLOR)"
			@echo "Use $(BLUE_COLOR)./cub3D$(NO_COLOR) to launch the program"

clean:
			@make clean -sC $(LIBFT_DIR)
			@$(RM) -r $(OBJ_DIR)
			@echo "$(ERROR_COLOR)Dependencies and objects removed$(NO_COLOR)"

fclean:		
			@make fclean -sC $(LIBFT_DIR)
			@$(RM) -r $(OBJ_DIR)
			@$(RM) $(NAME)
			@echo "$(ERROR_COLOR)$(NAME) removed$(NO_COLOR)"

re:			fclean all

-include $(DEPS)

.PHONY: all clean fclean re libft

################################################################################
#                                    COLOR                                     #
################################################################################

NO_COLOR		=	\x1b[0m
OK_COLOR		=	\x1b[32;01m
ERROR_COLOR		=	\x1b[31;01m
WARN_COLOR		=	\x1b[33;01m
BLUE_COLOR		=	\x1b[34;01m

OK_STRING		=	$(OK_COLOR)[OK]$(NO_COLOR)
ERROR_STRING	=	$(ERROR_COLOR)[ERRORS]$(NO_COLOR)
WARN_STRING		=	$(WARN_COLOR)[WARNINGS]$(NO_COLOR)
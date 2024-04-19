# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 17:33:17 by erosas-c          #+#    #+#              #
#    Updated: 2024/04/19 16:55:10 by aaespino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  		=	libft.a

INCLUDE		=	inc/

SRC_DIR		=	src/
SRC_FILES 	= 	ft_arrfree.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
				ft_toupper.c ft_tolower.c ft_strchr.c ft_strrcmp.c ft_istype_iter.c \
				ft_strnchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_isint.c \
				ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_dbllen.c ft_isspace.c\
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_strcmp.c get_next_line.c \

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR		= 	obj/
OBJ_FILES	=	$(SRC_FILES:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

DEP_FILES	=	$(SRC_FILES:.c=.d)
DEPS		=	$(addprefix $(OBJ_DIR), $(DEP_FILES))

CC 			= 	gcc
FLAGS 		= 	-Wall -Werror -Wextra -MDD
RM    		= 	rm -rf

INC			=	-I inc/

all: 		$(NAME)

$(NAME): 	$(OBJ_DIR) $(OBJS)
			@ar rcs $@ $(OBJS)
			@echo "\033[K$(CLEAN_CAR)$(OK_COLOR)Libft compiled!$(NO_COLOR)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_DIR)
			@printf "$(CLEAN_CAR)$(OK_COLOR)[Compiling libft...]$(NO_COLOR)\r"
			@$(CC) $(CFLAGS) $(INC) -g -c $< -o $@

$(OBJ_DIR):
			@mkdir -p $@			

clean:	
		@$(RM) $(OBJ_DIR)
		
fclean: clean
		@$(RM) $(NAME)
		@echo "$(ERROR_COLOR)$(NAME) removed$(NO_COLOR)"

re: 	fclean all

-include $(DEPS)

.PHONY: all clean fclean re

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
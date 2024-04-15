# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 17:33:17 by erosas-c          #+#    #+#              #
#    Updated: 2024/04/01 18:01:48 by erosas-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  		=	libft.a

INCLUDE		=	inc/

SRC_DIR		=	src/
SRC_FILES 	= 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
				ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
				ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
				ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_dbllen.c \
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_strcmp.c
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

$(NAME): 	$(OBJS)
			ar rcs $@ $(OBJS)

$(OBJS): 	| $(OBJ_DIR)

$(OBJ_DIR):	
			mkdir $@

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				$(CC) $(CFLAGS) $(INC) -g -c $< -o $@
			
clean:	
		@$(RM) $(OBJS) $(DEPS)

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(OBJ_DIR)

re: 	fclean all

-include $(DEPS)

.PHONY: all clean fclean re
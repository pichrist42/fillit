# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/19 09:41:20 by pichrist          #+#    #+#              #
#    Updated: 2017/05/23 03:54:34 by pichrist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT
CC = gcc
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
NAME = fillit

# DIRECTORIES
SRC_PATH = ./
SRC_NAME = 	fillit.c display_square.c read_file.c find_square_size.c \
			gen_square.c find_tetri.c the_mind.c create_tetri.c parse_file.c \
			the_bonus_mind.c destroy_tetri.c
HEAD_PATH = ./
HEAD_NAME = fillit.h libft/libft.h
LIB_MAKE = libft
LIB = libft/libft.a

# FILES
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
HEAD = $(addprefix $(HEAD_PATH),$(HEAD_NAME))

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) :
	@$(MAKE) -C $(LIB_MAKE)
	@$(CC) $(SRC) $(LIB) -o $(NAME) $(FLAGS)

clean :
	@$(MAKE) -C $(LIB_MAKE) clean
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(LIB)
	@rm -f $(NAME)

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/19 09:41:20 by pichrist          #+#    #+#              #
#    Updated: 2017/05/13 20:41:25 by pichrist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT
CC = gcc
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
NAME = fillit

# DIRECTORIES
SRC_PATH = src/fillit/
SRC_NAME = 	fillit.c display_square.c read_file.c find_square_size.c \
			gen_square.c find_tetri.c the_mind.c create_tetri.c parse_file.c
HEAD_PATH = includes/
HEAD_NAME = fillit/fillit.h libft/libft.h
LIB = includes/libft/libft.a

# FILES
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
HEAD = $(addprefix $(HEAD_PATH),$(HEAD_NAME))

all : $(NAME)

$(NAME) :
	@$(CC) $(SRC) $(LIB) -o $(NAME) $(FLAGS)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

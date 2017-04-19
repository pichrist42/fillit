# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/19 09:41:20 by pichrist          #+#    #+#              #
#    Updated: 2017/04/19 21:18:16 by pichrist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT
CC = gcc
OBJ = $(SRC:.c=.o)
# FLAGS = -Wall -Wextra -Werror
NAME = fillit

# DIRECTORIES
SRC_PATH = src/
SRC_NAME = 	fillit.c display_square.c read_file.c find_square_size.c \
			gen_square.c find_tetri.c the_mind.c create_tetri.c parse_file.c
HEAD_PATH = includes/
HEAD_NAME = fillit.h libft.h
LIB = includes/libft.a

# FILES
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
HEAD = $(addprefix $(HEAD_PATH),$(HEAD_NAME))

all : $(NAME)

$(NAME) :
	@echo "\033[31mCOMPILATION SANS FLAGS\n\033[0m\c"
	@$(CC) $(SRC) $(LIB) -o $(NAME)
	@echo "\033[1;37m$(NAME)\t\t\033[1;32m[Created]"
	@echo "\033[1;37mObject files\t\033[1;32m[Created]\033[1;37m"

clean :
	@rm -f $(OBJ)
	@echo "\033[1;37mObject files\t\033[1;34m[Deleted]"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[1;37m$(NAME)\t\t\033[1;34m[Deleted]"

re : fclean all

.PHONY : all, clean, fclean, re

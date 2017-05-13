# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/19 09:41:20 by pichrist          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2017/05/13 20:56:47 by flseaill         ###   ########.fr        #
=======
#    Updated: 2017/05/13 20:41:25 by pichrist         ###   ########.fr        #
>>>>>>> a79cfa3faa917194a380661f248fbd6bf93772c7
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
LIB_PATH  = src/libft/
LIB_NAME = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	  ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c \
	  ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c \
	  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c \
	  ft_strstr.c ft_tolower.c ft_toupper.c ft_itoa.c ft_putchar.c \
	  ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
	  ft_memalloc.c ft_memdel.c ft_strclr.c ft_strdel.c ft_striter.c \
	  ft_strmap.c ft_strnequ.c ft_strnew.c ft_strsplit.c \
	  ft_strsub.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
	  ft_lstmap.c ft_lstnew.c ft_abs.c ft_iterative_power.c ft_power.c \
	  ft_strchrp.c ft_strdupa.c ft_strdupu.c ft_strisalnum.c ft_strisalpha.c \
	  ft_strisascii.c ft_strisdigit.c ft_strisprint.c

# FILES
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
HEAD = $(addprefix $(HEAD_PATH),$(HEAD_NAME))
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))

all : $(NAME)

$(NAME) :
	@$(CC) $(SRC) $(LIB) -o $(NAME) $(FLAGS)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
<<<<<<< HEAD

.PHONY : all clean fclean re
=======
>>>>>>> a79cfa3faa917194a380661f248fbd6bf93772c7

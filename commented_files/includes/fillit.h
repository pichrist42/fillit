/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:54:50 by pichrist          #+#    #+#             */
/*   Updated: 2017/04/18 08:54:37 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct		s_tetri
{
	size_t			**block;
	char			alpha;
	struct s_tetri	*next;
	struct s_tetri	*prev;
}					t_tetri;

/*
** Creates a new tetri struct. Returns NULL if the allocation fails.
*/
t_tetri				*create_tetri();

/*
** Reads the tetrimino position from the input file and returns a t_tetri
** struct. Returns NULL in case of error.
*/
t_tetri				*find_tetri(char *file_content, int i, int j, \
	int block_read, t_tetri *first);
// t_tetri *find_tetri(char *file_content);
t_tetri				*push_up_tetri(t_tetri *first, t_tetri *t);
char				*the_mind(char *square, t_tetri *t, size_t sq_size);

/*
** Allocate the square holding the results of the program. Returns the
** allocated memory or NULL if failed.
*/
char				*gen_square(size_t sq_size);

/*
** Returns the minimum size of the square that could hold all the tetriminos.
*/
size_t				find_square_size(char *file_content);

/*
** Check the file validity. Returns 0 in case of success.
*/
int					parse_file(char *file_content);

/*
** Returns the content of the file, NULL in case of error.
*/
char				*read_file(char *str);
void				display_square(char *square);

/*
** DEBUG
*/
# define DEBUG 1
# define DEBUG_POS 0
# define DEBUG_PLACEMENT 1
# define DEBUG_CREATION_DETAILLED 1
# define DEBUG_CREATION_SPECIFIC 0

void				print_int(char *s, int v, int end);
void				print_char(char *s, char c, int end);
void				print_end();
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:54:50 by pichrist          #+#    #+#             */
/*   Updated: 2017/05/22 22:42:36 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

# define CHAR_ELEM '#'
# define CHAR_SPACE '.'
# define CHAR_NL '\n'

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
	int block_read);
void				find_tetri_sub(t_tetri **t, int *block_read, \
	int *off_read);
void				find_tetri_tri(int *i, int *j);
void				find_tetri_quad(int *i, int *j, t_tetri *t, \
	int *block_read);

/*
** Moves the tetriminos up or left on their own grid, in the struct. Calls
** itself until it has finished processing the whole struct, then returns the
** first item.
*/
t_tetri				*offset_tetri(t_tetri *first, t_tetri *t, int way);

/*
** Algorithm functions.
*/
int					formula(size_t sq_size, t_tetri *t, int i);
int					the_mind_sub(char **square, size_t square_size, t_tetri *t\
	, int rollback);
int					the_mind_tri(char *square, size_t square_size, t_tetri *t,\
	int *offset);
char				*the_mind_quad(char *square, size_t square_size, \
	t_tetri *t, int offset);
char				*the_mind(char *square, size_t square_size, t_tetri *t, \
	int rollback);
int					the_unknown(char *square, t_tetri *t);

/*
** Allocates the square holding the results of the program. Returns the
** allocated memory or NULL if failed.
*/
char				*gen_square(size_t sq_size);

/*
** Returns the minimum size of the square that could hold all the tetriminos.
*/
size_t				find_square_size(char *file_content);

/*
** Checks the file validity. Returns 1 in case of success.
*/
int					parse_file(char *file_content);
int					valid_pcs(char *pcs);
int					valid_pcs_sub(char *pcs, int i, int *link, int *dot);
int					valid_char(char to_check);

/*
** Reads the file and returns it's content, NULL in case of error.
*/
char				*read_file(char *str);

/*
** Displays the result of the program.
*/
void				display_square(char *square);

/*
** Second part of the main function.
*/
void				main_sub(char *file_content, size_t sq_size, char *square);

#endif

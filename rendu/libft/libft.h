/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 13:20:19 by pichrist          #+#    #+#             */
/*   Updated: 2017/01/30 03:48:57 by pichrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** 1. Basics 1 ****************************************************************
*/

/*
** ft_atoi converts the string into a number. If an abnormal character is  \
** read, conversion is stopped and the incomplete result is returned.
*/
int					ft_atoi(const char *s);

/*
** ft_bzero erases the n first characters of the string passed as a paramter.
*/
void				ft_bzero(void *s, size_t n);

/*
** ft_isalnum returns 1 if the character passed as a parameter is alphabetical\
** or a number, 0 otherwise.
*/
int					ft_isalnum(int c);

/*
** ft_isalpha returns 1 if the character passed as a parameter is \
** 	alphabetical, 0 otherwise.
*/
int					ft_isalpha(int c);

/*
** ft_isascii returns 1 if the character is part of the ascii table, 0 \
** otherwise.
*/
int					ft_isascii(int c);

/*
** ft_isdigit returns 1 if the character is a number, 0 otherwise.
*/
int					ft_isdigit(int c);

/*
** ft_isdigit returns 1 if the character is printable, 0 otherwise.
*/
int					ft_isprint(int c);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** Overlap problems might occur during the copy, use memmove instead
*/
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strncat(char *dest, const char *src, size_t nb);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strnstr(const char *big, const char *little, size_t \
	len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
int					ft_tolower(int c);
int					ft_toupper(int c);

/*
** 2. Basics 2 ****************************************************************
*/

/*
** ft_itoa converts the number passed as a parameter into a string.
*/
char				*ft_itoa(int n);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *c);
void				ft_putstr_fd(char const *c, int fd);

/*
** calloc equivalent
*/
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);

/*
** 3. Additional functions ****************************************************
*/

/*
** ft_lstadd adds the list element passed as a parameter at the begining of \
** the list passed as first parameter.
*/
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

/*
** 4. Bonus *******************************************************************
*/

/*
** ft_abs returns the absolute value of the paramter.
*/
size_t				ft_abs(int a);

/*
** ft_iterative_power returns the first parameter power the second one. \
** Iterative algorithm.
*/
int					ft_iterative_power(int n, int p);

/*
** ft_iterative_power returns the first parameter power the second one. \
** Recursive algorithm.
*/
int					ft_power(int n, int p);
int					ft_strchrp(char *s, char *item);

/*
** ft_strdupa creates a new string and copies the content of s onto this after \
** the first occurence of l met (not included). If s isn't defined, a null \
** pointer is returned. If l isn't defined or is empty, a copy of s is \
** returned.
*/
char				*ft_strdupa(char *s, char *l);

/*
** ft_strdupu creates a new string and copies the content of s onto this until \
** the first occurence of l met (not included). If S isn't defined, a null \
** pointer is returned. If l is not defined or is empty, a copy of s is \
** returned.
*/
char				*ft_strdupu(char *s, char *l);

/*
** ft_strisalnum returns 1 if the string contains only alphabetical or \
** numerical characters, 0 otherwise.
*/
int					ft_strisalnum(char *str);

/*
** ft_strisalpha returns 1 if the string contains only alphabetical \
** characters, 0 otherwise.
*/
int					ft_strisalpha(char *str);

/*
** ft_strisascii returns 1 if the string contains only ascii characters, \
** 0 otherwise.
*/

int					ft_strisascii(char *str);

/*
** ft_strisdigit returns 1 if the string contains only numbers, 0 otherwise.
*/
int					ft_strisdigit(char *str);

/*
** ft_strisprint returns 1 if the string is printable, 0 otherwise.
*/
int					ft_strisprint(char *str);
#endif

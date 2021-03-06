/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:12:40 by dlavaury          #+#    #+#             */
/*   Updated: 2018/05/04 16:40:09 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
**	BIBLIOTHEQUES
*/

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

/*
**    MACROS
*/

# define INTMAXLEN	9223372036854775807
# define BUFF_SIZE	128
# define IMAX		2147483647
# define IMIN		-2147483648

/*
**	STRUCTURES
*/

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**	PART 1
*/

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** PART 2
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** Bonus
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** My_functions
*/

int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_countnumber(int n);
void				ft_putnbrendl(int n);
int					ft_countwords(const char *s, const char c, size_t state);
void				ft_printstrsplit_tab(char **words);
t_list				*ft_strsplit_lst(char const *s, char c);
void				ft_putlst(t_list *lst, void (*f)(char const *));
size_t				ft_lstcount(t_list *lst);
t_list				*ft_fileaddone(t_list *lst);
t_list				*ft_filedelone(t_list *lst);
t_list				*ft_pileaddone(t_list *lst);
t_list				*ft_piledelone(t_list *lst);
t_list				*ft_strsplit_file(char const *s, char c);
t_list				*ft_strsplit_pile(char const *s, char c);
int					ft_str_is_printable(char *str);
int					ft_str_is_uppercase(char *str);
int					ft_str_is_numeric(char *str);
int					ft_str_is_alpha(char *str);
char				*ft_strlowercase(char *str);
char				*ft_strcapitalize(char *str);
int					ft_str_is_lowercase(char *str);
char				*ft_strupcase(char *str);
void				ft_swap(int *a, int *b);
int					ft_strchri_up(const char *s, unsigned c);
int					ft_strchri(const char *s, unsigned c);
size_t				ft_wstrlen(wchar_t *ws);
size_t				ft_wcharlen(wchar_t c);
void				ft_print_mem(const void *mem, size_t size,
								size_t elem, size_t opt);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 16:23:20 by msorin            #+#    #+#             */
/*   Updated: 2017/12/08 12:50:30 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

# define BUFF_SIZE 256

typedef struct s_list	t_list;

struct	s_list
{
	void	*content;
	size_t	content_size;
	t_list	*next;
};

/*
** part1
*/

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);

/*
** !part1
** part2
*/

void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char const *s);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_strclr(char *s);
void	ft_strdel(char **as);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	**ft_strsplit(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnew(size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);

/*
** !part2
** part3
*/

void	ft_lstadd(t_list **alst, t_list *new);
t_list	*ft_lstcpy(t_list *lst);
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list	*ft_lstnew(void const *content, size_t content_size);

/*
** !part3
** Bonus
*/

int		ft_max(int a, int b);
int		ft_min(int a, int b);
void	ft_putnbrendl(size_t n, size_t base);
char	*ft_initstr(char c, int sz);
char	*ft_strsplit_last(const char *str, const char c, int f);
char	*ft_strjoin_f(char *s1, char *s2, int f);
char	*ft_getenv(const char *val, const char **env);
char	*ft_strndup(const char *src, int len);
size_t	ft_nblen(int nb);

/*
** !Bonus
*/

#endif

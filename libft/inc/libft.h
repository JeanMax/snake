/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:13:23 by mcanal            #+#    #+#             */
/*   Updated: 2014/12/13 04:17:35 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 32
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
typedef struct s_list	t_list;
struct	s_list
{
	void	*content;
	size_t	content_size;
	t_list	*next;
};
typedef struct s_lst	t_lst;
struct	s_lst
{
	int		x;
	int		y;
	int		z;
	t_lst	*next;
	t_lst	*prev;
	t_lst	*body;
};

void	ft_putnbr_clr(int nbr, char *clr);
void    ft_putstr_clr(char const *s, char *clr);
void    ft_putendl_clr(char const *s, char *clr);
void    ft_putchar_clr(char c, char * clr);
void    ft_debugstr(char *name, char *str);
void    ft_debugnbr(char *name, int nbr);

int		get_next_line(int const fd, char **line);
int		ft_strindex(const char *s, int c);
int		ft_strrindex(const char *s, int c);
void	ft_lswap(t_lst *lst1, t_lst *lst2);
void	ft_ldellink(t_lst *lst);
int		ft_lisn(t_lst **alst, t_lst *lst);
void	ft_lrplc(t_lst *old, t_lst *new);
void	ft_linser(t_lst **alst, t_lst *new);
int		ft_lislast(t_lst **alst);
int		ft_lisfirst(t_lst **alst);
int		ft_llen(t_lst **alst);
t_lst	*ft_llast(t_lst **alst);
t_lst	*ft_lfirst(t_lst **alst);
t_lst	*ft_lat(t_lst **alst, size_t n);
int		ft_lisempty(t_lst **alst);
void	ft_laddlast(t_lst **alst, t_lst *new);
t_lst	*ft_lnew(int x, int y, int z);
void	ft_ladd(t_lst **alst, t_lst *new);
void	ft_liter(t_lst *lst, void (*f)(t_lst *elem));
void	ft_lstdellink(t_list **alst, t_list *lst);
int		ft_lstisn(t_list **alst, t_list *lst);
t_list	*ft_lstfind(t_list **alst, void *data);
void	ft_lstrplc(t_list **alst, t_list *old, t_list *new);
void	ft_lstinser(t_list **alst, t_list *new);
int		ft_lstislast(t_list **alst);
int		ft_lstlen(t_list **alst);
t_list	*ft_lstlast(t_list **alst);
t_list	*ft_lstat(t_list **alst, size_t n);
int		ft_lstisempty(t_list **alst);
void	ft_lstaddlast(t_list **alst, t_list *new);
t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void	*ft_realloc(void *old, size_t old_size, size_t new_size);
int		ft_atoi(char *str);
int		ft_isalnum(int i);
int		ft_isalpha(int i);
int		ft_isascii(int i);
int		ft_isdigit(int i);
int		ft_isprint(int i);
int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_isblank(int c);
int		ft_iscntrl(int c);
int		ft_isgraph(int c);
int		ft_ispunct(int c);
int		ft_isspace(int c);
int		ft_isxdigit(int c);
char	*ft_strcat(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(char *src);
size_t	ft_strlen(const char *str);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strstr(const char *str, const char *to_find);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strncat(char *dest, const char *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
void	*ft_memalloc(size_t size);
void	ft_putchar(char c);
void	ft_putnbr(int nbr);
void	ft_putstr(char const *s);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_striter(char *s, void (*f)(char*));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_itoa(int n);
void	ft_strclr(char *s);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:34:44 by nsauret           #+#    #+#             */
/*   Updated: 2024/08/17 00:36:58 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "ft_printf/ft_printf.h"
# include "ft_get_next_line/get_next_line.h"

typedef struct s_list
{
	struct s_list	*prev;
	int				content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *nptr);
void	ft_bzero(char *s, int n);
void	*ft_calloc(size_t ft_nmemb, size_t ft_size);
void	ft_freetabstr(char **tab);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int ft_n);
int		ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstiter(t_list *lst, void (*f)(int));
t_list	*ft_lstlast(t_list *ft_lst);
t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int));
t_list	*ft_lstnew(int content);
void	ft_lstpop(t_list **lst);
int		ft_lstsize(t_list *lst);
void	*ft_memchr(const void *ft_s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *ft_dest, const void *ft_src, size_t ft_n);
void	*ft_memmove(void *ft_dest, void *ft_src, size_t ft_n);
void	*ft_memset(void *ft_s, int c, size_t ft_n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int ft_n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t siz);
size_t	ft_strlcpy(char *dst, const char *src, size_t siz);
int		ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_uitoa(unsigned int ft_n);

#endif

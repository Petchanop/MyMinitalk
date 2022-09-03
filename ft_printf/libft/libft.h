/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:48:13 by npiya-is          #+#    #+#             */
/*   Updated: 2022/03/23 18:25:25 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_atoi(char const *num);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_memcmp(void const *s1, void const *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
void	ft_bzero(void *b, size_t len);
void	*ft_calloc(size_t n, size_t size);
void	*ft_memccpy(void *dst, void const *src, int c, size_t n);
void	*ft_memchr(void const *ptr, int c, size_t len);
void	*ft_memcpy(void *dst, void const *src, size_t len);
void	*ft_memmove(void *dst, void const *src, size_t len);
void	*ft_memset(void *mem, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_itoa(long long n);
char	**ft_split(char const *s, char c);
char	*ft_strchr(char const *p, int ch);
char	*ft_strdup(char const *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(char const *str, char const *to_find, size_t slen);
char	*ft_strrchr(char const *cp, int ch);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(char const *str);
size_t	ft_strlcpy(char *dst, char const *src, size_t len);
size_t	ft_strlcat(char *dst, char const *src, size_t size);

typedef struct s_list
{
	struct s_list	*next;
	void			*content;
}	t_list;

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//void	ft_putstr(char const *str);
#endif

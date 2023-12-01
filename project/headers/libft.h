/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreys <kirrill20030@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:46:16 by kreys             #+#    #+#             */
/*   Updated: 2023/11/01 19:19:24 by kreys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
void (*del)(void *));

t_list				*ft_lstnew(void *content);
t_list				*ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);

int					ft_isascii(int symbol);
int					ft_lstsize(t_list *lst);
int					ft_atoi(const char *str);
int					ft_isalnum(int symbol);
int					ft_isalpha(int symbol);
int					ft_isalpha(int symbol);
int					ft_isdigit(int symbol);
int					ft_isprint(int symbol);
int					ft_memcmp(const void *dst, const void *src, size_t n);
int					ft_strlen(const char *str);
int					ft_tolower(int symbol);
int					ft_toupper(int symbol);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);

unsigned int		ft_strlcpy(char *dest, const char *src, size_t size);
unsigned int		ft_strlcat(char *dest, const char *src, unsigned int size);

char				*ft_strchr(const char *src, int symbol);
char				*ft_strdup(char *src);
char				*ft_strncpy(char *dest, const char *src, unsigned int n);
char				*ft_strnstr(const char*str, const char *to_find, size_t n);
char				*ft_strrchr(char *src, int symbol);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(const char *str, char charset);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_bzero(void *b, size_t len);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *src1, int symbol, size_t n);
void				ft_putendl_fd(char *s, int fd);

#endif
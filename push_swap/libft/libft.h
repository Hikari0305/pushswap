/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawawak <skawawak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 22:22:27 by skawawak          #+#    #+#             */
/*   Updated: 2026/07/19 05:09:06 by skawawak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_isdigit(int c);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
t_stack				*ft_lstlast(t_stack *lst);
t_stack				*ft_lstnew(int value);
void				ft_lstadd_back(t_stack **lst, t_stack *new_node);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
int					strategy_selector_check(char **args);
#endif

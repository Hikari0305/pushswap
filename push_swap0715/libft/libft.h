#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

int		ft_isdigit(int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_stack	*ft_lstnew(int value);
void	ft_lstadd_back(t_stack **lst, t_stack *new_node);
size_t  ft_strlen(const char *s);
char    *ft_substr(char const *s, unsigned int start, size_t len);
void    ft_putchar_fd(char c, int fd);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_putchar_fd(char c, int fd);
t_stack	*ft_lstlast(t_stack *lst);

#endif
NAME    = libft.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = ft_isdigit.c \
          ft_strcmp.c \
          ft_strdup.c \
          ft_strjoin.c \
          ft_split.c \
          ft_putstr_fd.c \
          ft_putnbr_fd.c \
          ft_putchar_fd.c \
          ft_strlen.c \
          ft_substr.c \
          ft_lstnew.c \
          ft_lstadd_back.c \
          ft_lstlast.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
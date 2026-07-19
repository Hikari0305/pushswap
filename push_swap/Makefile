NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = main.c \
	  args_config.c \
	  bench_utils.c \
	  common_utils.c \
	  op_push.c \
	  op_reverse.c \
	  op_rotate.c \
	  op_swap.c \
	  parse_utils.c \
	  sort_chunk.c \
	  sort_radix.c \
	  sort_selection.c \
	  sort_utils.c
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: 
	rm -f $(OBJS)
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

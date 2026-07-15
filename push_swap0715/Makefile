NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Libftの場所と、生成されるライブラリファイル(.a)を指定
LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = main.c bench_utils.c compression.c op_push.c op_reverse.c op_rotate.c op_swap.c parse_utils.c selection_sort.c utils.c chunk_sort.c
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

# push_swap を作る前に、先に libft.a をビルドさせる
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# libft ディレクトリに移動して、そっちの Makefile を実行する命令
$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -f clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make -f fclean -C $(LIBFT_DIR)

re: fclean all

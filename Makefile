NAME = push_swap
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror -ggdb

SOURCES = main.c stack.c swap.c push_rotate.c revrotate.c\
			utils.c

OBJS = $(SOURCES:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	@cc $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	@cc $(FLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT):
	@make -s -C libft bonus

clean:
	rm -rf $(OBJS)
	@make -C libft clean

fclean: clean
	rm -f $(NAME)
	@make -C libft clean

re: fclean all
NAME = push_swap
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror -ggdb

SOURCES = main.c stack.c swap.c push_rotate.c revrotate.c\
			utils.c sorting.c sorting_utils.c

OBJS = $(SOURCES:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	@cc $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo push_swap OK 

%.o: %.c
	@cc $(FLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT):
	@make -s -C libft bonus
	@echo libft OK

clean:
	@rm -rf $(OBJS)
	@make -s -C libft clean
	@echo clean OK

fclean: clean
	@rm -f $(NAME)
	@make -s -C libft fclean

re: fclean all
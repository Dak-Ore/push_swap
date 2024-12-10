NAME = push_swap
FLAGS = -Wall -Wextra -Werror -ggdb

SOURCES = main.c

OBJS = $(SOURCES:.c=.o)

$(NAME): $(OBJS)
	cc $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
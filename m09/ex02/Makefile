CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = PmergeMe
RM = rm -f
INCLUDE = -I.
ARGS = `shuf -i 1-1000 -n 3000 | tr "\n" " " `

SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

test: $(NAME)
	./$(NAME) $(ARGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re valgrind
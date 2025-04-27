CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = RPN
RM = rm -f
INCLUDE = -I.
ARGS = "7 7 * 7 -"

SRCS = main.cpp RPN.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

test: $(NAME)
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	./$(NAME) "7 7 * 7 -"
	./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	./$(NAME) "(1 + 1)"
	./$(NAME) "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -"
	./$(NAME) " 1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 / "

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re valgrind
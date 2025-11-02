CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = btc
RM = rm -f
INCLUDE = -I.
ARGS = input.txt

SRCS = main.cpp BitcoinExchange.cpp 
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
CC = c++
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
NAME = a.out

SRCS = main.cpp Srcs/Animal.cpp Srcs/Dog.cpp Srcs/Cat.cpp\
		 Srcs/WrongAnimal.cpp Srcs/WrongCat.cpp Srcs/Brain.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re valgrind
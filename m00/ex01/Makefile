CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I./includes
RM = rm -rf
NAME = phonebook

SRCS = main.cpp srcs/Contact.cpp srcs/PhoneBook.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	${CC} ${CFLAGS} -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run:
	./$(NAME)

.PHONY: all clean fclean re run
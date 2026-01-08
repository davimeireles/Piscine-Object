NAME = ex01
SOURCE = main.cpp Vector2.cpp Graph.cpp
CCFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

all: $(NAME)

$(NAME):
	$(CC) $(CCFLAGS) -I . $(SOURCE) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

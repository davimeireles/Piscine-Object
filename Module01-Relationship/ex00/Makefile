NAME = ex00
SOURCE = main.cpp Shovel_Aggregation.cpp Worker_Aggregation.cpp
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
NAME_AGG = ex00_aggregation
NAME_COMP = ex00_composition
NAME_INH = ex00_inherence
NAME_ASSOC = ex00_association

SOURCE_AGG = main_Aggregation.cpp Shovel_Aggregation.cpp Worker_Aggregation.cpp
SOURCE_COMP = main_Composition.cpp Shovel_Aggregation.cpp Worker_Composition.cpp
SOURCE_INH = main_Inherence.cpp Tool_Inherence.cpp Shovel_Inherence.cpp Hammer_Inherence.cpp Worker_Inherence.cpp
SOURCE_ASSOC = main_Association.cpp Workshop_Association.cpp Worker_Association.cpp

CCFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

all: $(NAME_AGG) $(NAME_COMP) $(NAME_INH) $(NAME_ASSOC)

$(NAME_AGG):
	$(CC) $(CCFLAGS) -I . $(SOURCE_AGG) -o $(NAME_AGG)

$(NAME_COMP):
	$(CC) $(CCFLAGS) -I . $(SOURCE_COMP) -o $(NAME_COMP)

$(NAME_INH):
	$(CC) $(CCFLAGS) -I . $(SOURCE_INH) -o $(NAME_INH)

$(NAME_ASSOC):
	$(CC) $(CCFLAGS) -I . $(SOURCE_ASSOC) -o $(NAME_ASSOC)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME_AGG) $(NAME_COMP) $(NAME_INH) $(NAME_ASSOC)

re: fclean all

.PHONY: all clean fclean re
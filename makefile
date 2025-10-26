# Makefile

NAME = sokoban

SRCS = main.c \
	affichage.c \
	generation.c 

all: $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all
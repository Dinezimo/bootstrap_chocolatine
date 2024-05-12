##
## EPITECH PROJECT, 2023
## makefile
## File description:
## programm
##

NAME =	my_rpg

SRC =	$(wildcard main/*.c) \
		$(wildcard game/*.c) \
		$(wildcard cinématique/*.c)	\
		$(wildcard animation/*.c)

OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -lm -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio
	gcc interface.c `pkg-config --cflags --libs gtk+-3.0` -o Elora

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

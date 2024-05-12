##
## EPITECH PROJECT, 2023
## makefile
## File description:
## programm
##

NAME =	dialogue

SRC =		$(wildcard *.c)

OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -lm -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -g3

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

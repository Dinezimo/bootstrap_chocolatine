##
## EPITECH PROJECT, 2023
## makefile
## File description:
## programm
##

NAME =	my_paint

SRC =		$(wildcard *.c)

OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -lm -lcsfml-graphics

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

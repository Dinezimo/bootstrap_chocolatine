##
## EPITECH PROJECT, 2023
## makefile
## File description:
## programm
##

NAME =	sandpile  

UNITEST	=	src/parsing_tools.c

SRC =		$(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

tests_run:
	gcc test.c -o unit_tests $(UNITEST) --coverage -lcriterion -lm
	./unit_tests
	gcovr --exclude unit_tests/ --branches
	gcovr --exclude	unit_tests/

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) -lm

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

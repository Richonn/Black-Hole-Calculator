##
## EPITECH PROJECT, 2024
## Black-Hole-Calculator
## File description:
## Makefile
##

CC = g++

CFLAGS	+=	-Wall -Wextra -pedantic -std=c++17 -lncurses

NAME	= Black-Hole-Calculator

SRC	=	$(wildcard *.cpp)

OBJ	= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## file making
##

NAME    = solver

CC    = gcc

RM    = rm -f

SRC    = main.c								\

OBJ    = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -pedantic -I../include -g3

LIBFLAG    = -L ../lib/my/ -lmy -I ../include -g3

all: $(NAME)

$(NAME): $(OBJ)
	cd ../lib/my/ && make
	$(CC) $(SRC) -o $(NAME) $(LIBFLAG)

clean:
	$(RM) *.o

fclean:
	$(RM) $(NAME)
	$(RM) $(OBJS)

re: fclean all

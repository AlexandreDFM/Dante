##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## file making
##

NAME    = generator

CC    = gcc

RM    = rm -f

SRC    = main.c								\
		recursive_backtracking.c			\
		my_itoa.c							\
		create_tab.c						\

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

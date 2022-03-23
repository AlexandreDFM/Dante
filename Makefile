##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## file making
##

RM    = rm -f

all:
	make -C ./lib/my
	make -C ./generator/
	make -C ./solver/

clean:
	make -C ./generator/ clean
	make -C ./solver/ clean
	make -C ./lib/my/ clean

fclean:
	make -C ./lib/my/ fclean
	make -C ./generator/ fclean
	make -C ./solver/ fclean

re: fclean all

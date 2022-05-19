##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	main.c				\
		open_file.c			\
		check_map.c			\
		check_map2.c		\
		check_pos_navy.c	\
		is_stacked.c		\
		map.c				\
		map2.c				\
		navy.c				\
		navy2.c				\
		navy3.c				\
		navy4.c				\
		players.c			\
		conversion.c		\
		msg.c				\
		is_finished.c		\
		attack.c			\
		receive_atk.c

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

all:	$(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) -I include -L lib -lmy

clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean:
	make clean
	make fclean -C lib/my
	rm -f $(NAME)

re:	fclean all

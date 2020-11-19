##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	my_getnbr.c			\
		my_putchar.c			\
		my_put_nbr.c			\
		my_putstr.c			\
		my_revstr.c			\
		my_strcmp.c			\
		my_strcpy.c			\
		my_strlen.c			\
		my_strncmp.c			\
		my_strncpy.c			\
		my_swap.c			\
		my_strdup.c

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-I ../../include/

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

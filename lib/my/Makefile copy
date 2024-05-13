##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for my_printf
##

SRC	=	my_printf.c				\
		my_putstr.c				\
		my_putchar.c			\
		my_strlen.c				\
		my_put_nbr.c			\
		my_put_flt.c			\
		my_compute_power_rec.c	\
		my_strcpy.c				\
		flags_first.c			\
		flags_second.c			\
		flags_third.c			\
		flags_fourth.c			\
		flags_fifth.c			\
		convert.c				\
		count_num.c				\
		my_strcat.c				\
		flag_g.c				\
		flag_g_functions.c		\
		my_atoi.c				\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f *~
	rm -f *#
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

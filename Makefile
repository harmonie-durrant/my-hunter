##
## EPITECH PROJECT, 2022
## csfml
## File description:
## Makefile for csfml
##

SRC		=	main.c				\
			game_loop.c			\
			events.c			\
			init.c				\
			create_textures.c	\
			create_clocks.c		\
			menu_loops.c		\
			main_menu_btns.c	\
			hearts.c			\
			create_m_textures.c	\
			destroy.c			\
			sfx_change.c		\
			score.c				\

OBJ	=	$(SRC:.c=.o)

CFLAGS = -I./include/

NAME	=	my_hunter

LIBDIR	=	./lib/my

LIBINC	=	-L$(LIBDIR) -lmy

CSFMLFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(OBJ):
		gcc -c $(SRC) $(CFLAGS)

$(NAME):	$(OBJ)
		make -C $(LIBDIR)
		gcc -o $(NAME) $(SRC) -I./include/ $(CSFMLFLAGS) $(LIBINC)

debug:
		make fclean
		make $(NAME)
		./$(NAME)

debug-help:
		make fclean
		make $(NAME)
		./$(NAME) -h

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f \#*#

fclean: clean
	make -C $(LIBDIR) fclean
	rm -f $(NAME)

re: fclean $(NAME)

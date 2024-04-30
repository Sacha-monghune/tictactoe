##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -Werror

SRC	=	str_to_word_array_dop.c \
		main.c \
		fill_map.c \
		free_tab.c \
		place.c \
		main1.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	tictactoe

PROG	=	tictactoe

all:	$(NAME)

$(NAME):	$(OBJ)

	gcc $(CFLAGS) -o $(PROG) $(OBJ)

debug:
	gcc $(SRC) -o $(PROG) -ggdb -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) *~ vgcore* $(PROG)

re:	fclean all

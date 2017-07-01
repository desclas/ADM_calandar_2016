##
## Makefile for  in /home/mathias/Bureau/projet_epitech/synthese/ADM_calandar_2016
## 
## Made by Mathias
## Login   <mathias@epitech.net>
## 
## Started on  Sat Jul  1 13:33:55 2017 Mathias
## Last update Sat Jul  1 13:44:18 2017 Mathias
##

SRC	=	src/append.c		\
		src/cmp.c		\
		src/exclude.c		\
		src/free_and_gnl.c	\
		src/get_emp.c		\
		src/how_num.c		\
		src/info.c		\
		src/new_invite.c	\
		src/print_emp.c		\
		src/sort_emp.c		\
		src/sort_meet.c		\
		src/test.c

OBJ	=	$(SRC:.c=.o)

NAME	=	calandar

CFLAGS	+=	-Iinclude -pedantic -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

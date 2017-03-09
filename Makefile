##
## Makefile for philo in /home/brout_m/rendu/system/PSU_2016_philo
##
## Made by Brout
## Login   <marc.brout@epitech.eu>
##
## Started on  Mon Jan 23 13:38:11 2017 Brout
## Last update Mon Mar  6 17:33:47 2017 duhieu_b
##

MAKE_DIR=	./

NAME=		philo

SRC_DIR=	./src/

SRC_FIL=	philo.c \
			letsThink.c \
			action.c

SRC= 		$(addprefix $(SRC_DIR), $(SRC_FIL))

OBJ=		$(SRC:.c=.o)

INC=		./include

CC=			gcc

INC= 		-I./include -lriceferee -lpthread -L./

ifeq ($(DEBUG), yes)
CFLAGS=	  	-g -W -Wall -Wextra -Werror $(INC)
else
CFLAGS=	  	-W -Wall -Wextra -Werror $(INC)
endif

RM=		rm -rf

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(INC)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all

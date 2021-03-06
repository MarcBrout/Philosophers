##
## Makefile for philo in /home/brout_m/rendu/system/PSU_2016_philo
##
## Made by Brout
## Login   <marc.brout@epitech.eu>
##
## Started on  Mon Jan 23 13:38:11 2017 Brout
## Last update Fri Mar 17 10:49:59 2017 brout_m
##

SANITIZE=	no

DEBUG=		no

MAKE_DIR=	./

NAME=		philo

SRC_DIR=	./src/

SRC_FIL=	philo.c \
		letsThink.c \
		action.c \
		checks.c

SRC= 		$(addprefix $(SRC_DIR), $(SRC_FIL))

OBJ=		$(SRC:.c=.o)

INC=		./include

CC=		gcc

INC= 		-I./include

LDFLAGS=	-lriceferee -lpthread -L./

ifeq ($(DEBUG), yes)
CFLAGS=	  	-g -W -Wall -Wextra -Werror $(INC)
else
CFLAGS=	  	-W -Wall -Wextra -Werror $(INC)
endif

ifeq ($(SANITIZE), yes)
CC +=		-fsanitize=thread
endif

RM=		rm -rf

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(INC) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all

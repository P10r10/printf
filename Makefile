# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsantia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 15:09:59 by alsantia          #+#    #+#              #
#    Updated: 2021/04/03 10:48:51 by alsantia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = $(wildcard srcs/*.c)
OBJECTS = $(patsubst %.c,%.o, $(SOURCES))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = libftprintf.a
RM = rm -f
AR = ar -src

.PHONY: all clean fclean re bonus

all: $(NAME) 

$(NAME): $(OBJECTS)
	$(AR) $@ $?

clean:
	$(RM) $(wildcard srcs/*.o)

fclean:
	$(RM) $(NAME)

re: fclean all

bonus: #for later

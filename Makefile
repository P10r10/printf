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

SRCS = ft_fetch.c ft_fill.c ft_isdigit.c ft_isspecifier.c ft_printf.c\
ft_putchar.c ft_putnbr.c ft_putnbr_h.c ft_putnbr_u.c ft_putstr.c ft_putstr_n.c\
ft_strdup.c ft_str_reverse.c ft_strdup.c ft_strlen.c ft_treat_type_c.c\
ft_treat_type_d.c ft_treat_type_p.c ft_treat_type_perc.c ft_treat_type_s.c\
ft_treat_type_u.c ft_treat_type_x.c\

SOURCES = $(addprefix srcs/,$(SRCS))
OBJECTS = $(patsubst %.c,%.o, $(SOURCES))
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = libftprintf.a
RM = rm -f
AR = ar -src

all: $(NAME) 

$(NAME): $(OBJECTS)
	$(AR) $@ $?

clean:
	$(RM) $(wildcard srcs/*.o)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
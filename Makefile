# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 18:21:29 by nholbroo          #+#    #+#              #
#    Updated: 2023/12/06 20:16:25 by nholbroo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS= -Wall -Wextra -Werror
OPTIONS = -c

SRC= 	ft_printf.c ft_putchar.c ft_puthexa_lower.c ft_puthexa_upper.c ft_putnbr.c ft_putpercent.c \
		ft_putptr.c ft_putstr.c ft_putuint.c ft_strlen.c

OBJ=$(SRC:.c=.o)

NAME= libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(OPTIONS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

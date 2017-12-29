#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okovalov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/13 13:58:53 by okovalov          #+#    #+#              #
#    Updated: 2017/09/13 13:59:42 by okovalov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRC = 	printf.c \
        ft_libfunc.c \
        ft_atoi.c \
        cast.c \
        wchar.c \
        spec.c \
        castux.c \
        castind.c \
        flag.c \

OBJ = $(SRC:.c=.o)

CC = gcc

FLGS = -c -Wall -Wextra -Werror

HEADER = -I ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -o $@ $<

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
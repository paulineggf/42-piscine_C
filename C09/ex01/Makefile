# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pganglof <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 19:52:51 by pganglof          #+#    #+#              #
#    Updated: 2019/06/22 22:26:24 by pganglof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

INCLUDE = ./includes/

SRCS = 	./srcs/ft_swap.c 	\
		./srcs/ft_putstr.c 	\
		./srcs/ft_strlen.c 	\
		./srcs/ft_strcmp.c 	\
		./srcs/ft_putchar.c

CFLAGS = -Wall -Wextra -Werror -I ${INCLUDE}

OBJS = ${SRCS:.c=.o}

RM = rm -f

all: ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:	clean
	rm ${NAME}

re:	fclean all

.PHONY: all	clean fclean re

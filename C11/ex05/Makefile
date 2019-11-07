# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pganglof <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/27 15:26:48 by pganglof          #+#    #+#              #
#    Updated: 2019/06/27 15:27:18 by pganglof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= do-op
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INCL	= includes

SRCS	= ./srcs/ft_plus.c		\
		  ./srcs/ft_moins.c		\
		  ./srcs/ft_div.c		\
		  ./srcs/ft_mult.c		\
		  ./srcs/ft_mod.c		\
		  ./srcs/ft_putnbr.c	\
		  ./srcs/ft_putchar.c	\
		  ./srcs/ft_putstr.c	\
		  ./srcs/ft_atoi.c		\
		  ./srcs/ft_do_op.c

OBJS	= ${SRCS:.c=.o}

.c.o:
					${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCL}

${NAME}:			${OBJS}
					${CC} -o ${NAME} -I ${INCL} ${OBJS}

all:				${NAME}

clean:
					rm -f ${OBJS}

fclean: 			clean
					rm -f ${NAME}

re:					fclean all

.PHONY: 			all clean fclean re

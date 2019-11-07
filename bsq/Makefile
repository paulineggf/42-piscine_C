# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcraipea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 01:17:21 by mcraipea          #+#    #+#              #
#    Updated: 2019/06/26 15:29:53 by pganglof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bsq
CPY		= bsq.cpy
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INCL	= includes

SRCS	= ./srcs/ft_algo.c				\
		  ./srcs/ft_define_params.c		\
		  ./srcs/ft_do_line.c			\
		  ./srcs/ft_entre_standard.c	\
		  ./srcs/ft_if_single_line.c	\
		  ./srcs/ft_params_line.c		\
		  ./srcs/ft_plus.c				\
		  ./srcs/ft_print_map.c			\
		  ./srcs/ft_putchar.c			\
		  ./srcs/ft_putstr.c			\
		  ./srcs/ft_search_square.c		\
		  ./srcs/ft_strlen.c			\
		  ./srcs/ft_while_file.c		\
		  ./srcs/ft_strjoin_cat.c		\
		  ./srcs/ft_strcpy.c			\
		  ./srcs/ft_strcat.c			\
		  ./srcs/main.c

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
					rm -f ${CPY}

re:					fclean all

.PHONY: 			all clean fclean re

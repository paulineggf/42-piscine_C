# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmarsauc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 13:46:08 by vmarsauc          #+#    #+#              #
#    Updated: 2019/06/23 19:13:10 by vmarsauc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/cpynbr.c srcs/ft_control_param.c srcs/ft_cpy_file.c srcs/ft_index.c srcs/ft_isspace.c srcs/ft_print_number.c srcs/ft_putstr.c srcs/ft_putstruct.c srcs/ft_strcat.c srcs/ft_strcpy.c srcs/ft_strdup.c srcs/ft_strdup_rl.c srcs/ft_strjoin_cat.c srcs/ft_strlen.c srcs/ft_strncmp.c srcs/ft_strncpy.c srcs/main.c

HEADER	= ./includes/

OBJS	= $(SRCS:.c=.o)

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror -I $(HEADER)

NAME = rush-02

%.o:	%.c
		$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	$(OBJS)
			$(CC) -o $@ $^

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonney <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 19:09:32 by rmonney           #+#    #+#              #
#    Updated: 2022/02/03 18:03:25 by rmonney          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS		= tools1.c actions.c ft_atoi.c main.c verifarg.c init.c start.c

OBJS		= ${SRCS:.c=.o}

INCLUDE		= -lpthread

RM			= rm -f

NAME		= philo

FLAGS		= -Wall -Wextra -Werror

CC			= gcc

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${FLAGS} ${INCLUDE} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

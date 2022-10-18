# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkhater <hkhater@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/16 06:30:32 by hkhater           #+#    #+#              #
#    Updated: 2022/10/16 06:57:59 by hkhater          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -rf

NAME	=	philosophers

INC		=	incs/philosophers.h

SRCS	=	srcs/*.c

OBJS	=	${SRCS:.c=.o}

.c.o:
			${CC} ${FLAGS} -c $< -o $(<:.c=.o)

${NAME}:	$(OBJS)
				$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all:	${NAME}

clean:
				${RM} $(OBJS)

fclean:	${RM}
				${RM} $(NAME)

re:				fclean all

.PHONY:		all clean fclean re c.o

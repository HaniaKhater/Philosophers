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

FILES	=	main.c \
		parsing.c \
		initialization.c \
		philo.c \
		routine.c \
		death.c \
		utils.c \

SRCS	=	${addprefix srcs/, $(FILES)}

OBJS	=	${SRCS:.c=.o}

.c.o:
			${CC} ${FLAGS} -c $< -o $(<:.c=.o)

${NAME}:	$(OBJS)
				$(CC) $(FLAGS) -pthread $(OBJS) -o $(NAME) -I $(INC)

all:	${NAME}

clean:
				${RM} $(OBJS)

fclean:		clean
				${RM} $(NAME)

re:				fclean all

.PHONY:		all clean fclean re c.o

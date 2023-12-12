# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 14:44:18 by lbirloue          #+#    #+#              #
#    Updated: 2023/10/30 16:46:23 by lbirloue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	 libftprintf.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

INCLUDES	=	-I libft.h

SRCS		=	utils_ft_printf.c \
				flags.c \
				flag_X.c \
				flag_xx.c \
				flag_di.c \
				flag_u.c \
				flag_p.c \
				counters.c \
				ft_printf.c \


OBJS		=	${SRCS:.c=.o}



all:		${NAME}


${NAME}:	${OBJS}
	ar -rc ${NAME} ${OBJS}


%.o:		%.c
	@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@


clean:
	rm -f ${OBJS}


fclean:		clean
	rm -f ${NAME}


re:			fclean all


.PHONY:		all clean fclean re 
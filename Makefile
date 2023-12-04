# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 18:14:38 by lbirloue          #+#    #+#              #
#    Updated: 2023/12/04 17:58:24 by lbirloue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

INCLUDES	=	so_long.h

SRCS		=	main.c \
				gnl42/get_next_line_utils.c \
				gnl42/get_next_line.c \
				so_long_utils.c \
				verif.c \



OBJS = $(SRCS:.c=.o)


all : $(NAME) 


$(NAME) : $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)



%.o : %.c so_long.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@


clean:
	rm -rf $(OBJS)


fclean: clean
	rm -rf $(NAME) 

re: fclean all


.PHONY:		all clean fclean re
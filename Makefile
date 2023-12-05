# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 18:14:38 by lbirloue          #+#    #+#              #
#    Updated: 2023/12/05 19:12:36 by lbirloue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

INCLUDES	=	./includes/so_long.h

SRCS		=	./srcs/main.c \
				./srcs/display.c \
				./srcs/gnl42/get_next_line_utils.c \
				./srcs/gnl42/get_next_line.c \
				./srcs/so_long_utils.c \
				./srcs/verif.c \



OBJS = $(SRCS:.c=.o)


all : $(NAME) 


$(NAME) : $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)



%.o : %.c ./includes/so_long.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@


clean:
	rm -rf $(OBJS)


fclean: clean
	rm -rf $(NAME) 

re: fclean all


.PHONY:		all clean fclean re
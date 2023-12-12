# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 18:14:38 by lbirloue          #+#    #+#              #
#    Updated: 2023/12/12 17:51:44 by lbirloue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= so_long

SRC				=	./srcs/main.c \
					./srcs/verif.c \
	                ./srcs/display.c \
	                ./srcs/move.c \
	                ./srcs/so_long_utils.c \
	                ./srcs/malloc_map.c \
					./srcs/gnl42/get_next_line_utils.c \
					./srcs/gnl42/get_next_line.c \
				
OBJ		         = ${SRC:.c=.o}

FT_PRINTF		= libftprintf.a

FT_PRINTF_PATH	= ft_printf

MLX				= libmlx.a

MLX_PATH		= mlx

CC				= gcc

RM				= rm -f

C_FLAGS			= -Wall -Wextra -Werror

MLX_FLAGS		= -L. -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

all: ${NAME}
${NAME}: ${OBJ} ${FT_PRINTF} ${MLX} 
	${CC} ${OBJ} -o ${NAME} ${FT_PRINTF} ${MLX_FLAGS} ${MLX} 

${FT_PRINTF}:
	${MAKE} -C ${FT_PRINTF_PATH}
	mv ${FT_PRINTF_PATH}/${FT_PRINTF} .

${MLX}:
	${MAKE} -C ${MLX_PATH}
	mv ${MLX_PATH}/${MLX} .

clean:
	${MAKE} clean -C ${FT_PRINTF_PATH}
	${MAKE} clean -C ${MLX_PATH}
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME} ${FT_PRINTF} ${MLX} 

re: fclean all

.PHONY: all clean fclean re
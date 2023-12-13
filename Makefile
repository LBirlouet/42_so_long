# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 18:14:38 by lbirloue          #+#    #+#              #
#    Updated: 2023/12/13 19:18:28 by lbirloue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= so_long

SRC				=	./srcs/main.c \
					./srcs/verif.c \
	                ./srcs/display.c \
					./srcs/all_display/display_back.c \
					./srcs/all_display/display_wall.c \
					./srcs/all_display/display_player.c \
					./srcs/all_display/display_exit.c \
					./srcs/all_display/display_enemy.c \
					./srcs/all_display/display_heart.c \
					./srcs/all_display/display_win.c \
					./srcs/all_display/display_loose.c \
					./srcs/all_display/display_collectible.c \
					./srcs/possible.c \
					./srcs/move.c \
					./srcs/key_press.c \
					./srcs/so_long_utils.c \
					./srcs/error_msg.c \
					./srcs/malloc_map.c \
					./srcs/gnl42/get_next_line_utils.c \
					./srcs/gnl42/get_next_line.c \
				
OBJ				= ${SRC:.c=.o}

FT_PRINTF		= libftprintf.a

FT_PRINTF_PATH	= ft_printf

MLX				= libmlx.a

MLX_PATH		= mlx

CC				= cc

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
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 18:14:38 by lbirloue          #+#    #+#              #
#    Updated: 2023/12/14 19:17:00 by lbirloue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= so_long

SRC_BONUS			=	./srcs_bonus/main.c \
					./srcs_bonus/verif.c \
					./srcs_bonus/verif_map.c \
					./srcs_bonus/verif_line.c \
					./srcs_bonus/display.c \
					./srcs_bonus/all_display/display_back.c \
					./srcs_bonus/all_display/display_wall.c \
					./srcs_bonus/all_display/display_player.c \
					./srcs_bonus/all_display/display_exit.c \
					./srcs_bonus/all_display/display_enemy.c \
					./srcs_bonus/all_display/display_heart.c \
					./srcs_bonus/all_display/display_win.c \
					./srcs_bonus/all_display/display_loose.c \
					./srcs_bonus/all_display/display_collectible.c \
					./srcs_bonus/all_display/display_score.c \
					./srcs_bonus/all_display/display_move.c \
					./srcs_bonus/all_display/display_collectible_nbr.c \
					./srcs_bonus/possible.c \
					./srcs_bonus/move.c \
					./srcs_bonus/ft_itoa.c \
					./srcs_bonus/key_press.c \
					./srcs_bonus/so_long_utils.c \
					./srcs_bonus/initialisation.c \
					./srcs_bonus/initialisation2.c \
					./srcs_bonus/error_msg.c \
					./srcs_bonus/malloc_map.c \
					./srcs_bonus/gnl42/get_next_line_utils.c \
					./srcs_bonus/gnl42/get_next_line.c \

OBJ_BONUS				= ${SRC_BONUS:.c=.o}

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
${NAME}: ${OBJ_BONUS} ${FT_PRINTF} ${MLX} 
	${CC} ${OBJ_BONUS} -o ${NAME} ${FT_PRINTF} ${MLX_FLAGS} ${MLX} 

${FT_PRINTF}:
	${MAKE} -C ${FT_PRINTF_PATH}
	mv ${FT_PRINTF_PATH}/${FT_PRINTF} .

${MLX}:
	${MAKE} -C ${MLX_PATH}
	mv ${MLX_PATH}/${MLX} .

clean:
	${MAKE} clean -C ${FT_PRINTF_PATH}
	${MAKE} clean -C ${MLX_PATH}
	${RM} ${OBJ_BONUS}

fclean: clean
	${RM} ${NAME} ${FT_PRINTF} ${MLX} 

re: fclean all

.PHONY: all clean fclean re
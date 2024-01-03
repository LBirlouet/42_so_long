# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/26 18:14:38 by lbirloue          #+#    #+#              #
#    Updated: 2024/01/03 11:32:01 by lbirloue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

SRC_MANDATORY		=	./srcs_mandatory/main.c \
					./srcs_mandatory/verif.c \
					./srcs_mandatory/verif_map.c \
					./srcs_mandatory/verif_line.c \
					./srcs_mandatory/display.c \
					./srcs_mandatory/all_display/display_back.c \
					./srcs_mandatory/all_display/display_wall.c \
					./srcs_mandatory/all_display/display_player.c \
					./srcs_mandatory/all_display/display_exit.c \
					./srcs_mandatory/all_display/display_collectible.c \
					./srcs_mandatory/possible.c \
					./srcs_mandatory/move.c \
					./srcs_mandatory/ft_itoa.c \
					./srcs_mandatory/key_press.c \
					./srcs_mandatory/so_long_utils.c \
					./srcs_mandatory/initialisation.c \
					./srcs_mandatory/initialisation2.c \
					./srcs_mandatory/error_msg.c \
					./srcs_mandatory/malloc_map.c \
					./srcs_mandatory/gnl42/get_next_line_utils.c \
					./srcs_mandatory/gnl42/get_next_line.c \

SRC_BONUS			=	./srcs_bonus/main_bonus.c \
					./srcs_bonus/verif_bonus.c \
					./srcs_bonus/verif_map_bonus.c \
					./srcs_bonus/verif_line_bonus.c \
					./srcs_bonus/display_bonus.c \
					./srcs_bonus/all_display_bonus/display_back_bonus.c \
					./srcs_bonus/all_display_bonus/display_wall_bonus.c \
					./srcs_bonus/all_display_bonus/display_player_bonus.c \
					./srcs_bonus/all_display_bonus/display_exit_bonus.c \
					./srcs_bonus/all_display_bonus/display_enemy_bonus.c \
					./srcs_bonus/all_display_bonus/display_heart_bonus.c \
					./srcs_bonus/all_display_bonus/display_win_bonus.c \
					./srcs_bonus/all_display_bonus/display_loose_bonus.c \
					./srcs_bonus/all_display_bonus/display_collectible_bonus.c \
					./srcs_bonus/all_display_bonus/display_score_bonus.c \
					./srcs_bonus/all_display_bonus/display_move_bonus.c \
					./srcs_bonus/all_display_bonus/display_collectible_nbr_bonus.c \
					./srcs_bonus/possible_bonus.c \
					./srcs_bonus/move_bonus.c \
					./srcs_bonus/ft_itoa_bonus.c \
					./srcs_bonus/key_press_bonus.c \
					./srcs_bonus/so_long_utils_bonus.c \
					./srcs_bonus/initialisation_bonus.c \
					./srcs_bonus/initialisation2_bonus.c \
					./srcs_bonus/error_msg_bonus.c \
					./srcs_bonus/malloc_map_bonus.c \
					./srcs_bonus/gnl42/get_next_line_utils.c \
					./srcs_bonus/gnl42/get_next_line.c \


OBJ_MANDATORY	= ${SRC_MANDATORY:.c=.o}

OBJ_BONUS		= ${SRC_BONUS:.c=.o}

FT_PRINTF		= libftprintf.a

FT_PRINTF_PATH	= ft_printf

MLX				= libmlx.a

MLX_PATH		= mlx

CC				= cc

RM				= rm -f

C_FLAGS			= -Wall -Wextra -Werror

MLX_FLAGS		= -L. -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	@$(CC) $(C_FLAGS) -c $< -o $@ > /dev/null 2>&1 && printf "\e[1;32m.\e[0m" || printf "\e[1;31m.\e[0m"

all: ${NAME}
${NAME}: ${OBJ_MANDATORY} ${FT_PRINTF} ${MLX}
	@${CC} ${OBJ_MANDATORY} -o ${NAME} ${FT_PRINTF} ${MLX_FLAGS} ${MLX} > /dev/null 2>&1 && printf "\e[1;32m.\e[0m" || printf "\e[1;31m.\e[0m"

bonus: ${NAME}_bonus
${NAME}_bonus: ${OBJ_BONUS} ${FT_PRINTF} ${MLX}
	@${CC} ${OBJ_BONUS} -o ${NAME} ${FT_PRINTF} ${MLX_FLAGS} ${MLX} > /dev/null 2>&1 && printf "\e[1;32m.\e[0m" || printf "\e[1;31m.\e[0m"

${FT_PRINTF}:
	@${MAKE} -C ${FT_PRINTF_PATH} > /dev/null 2>&1 && printf "\e[1;32m.\e[0m" || printf "\e[1;31m.\e[0m"
	@mv ${FT_PRINTF_PATH}/${FT_PRINTF} .

${MLX}:
	@${MAKE} -C ${MLX_PATH} > /dev/null 2>&1 && printf "\e[1;32m.\e[0m" || printf "\e[1;31m.\e[0m"
	@mv ${MLX_PATH}/${MLX} .


clean:
	@${MAKE} clean -C ${FT_PRINTF_PATH} > /dev/null 2>&1 && printf "\e[1;31m.\e[0m"
	@${MAKE} clean -C ${MLX_PATH} > /dev/null 2>&1 && printf "\e[1;31m.\e[0m"
	@${RM} ${OBJ_MANDATORY} > /dev/null 2>&1 && printf "\e[1;31m.\e[0m"
	@${RM} ${OBJ_BONUS} > /dev/null 2>&1 && printf "\e[1;31m.\e[0m"
	@${RM} ${MLX} > /dev/null 2>&1 && printf "\e[1;31m.\e[0m"
	@${RM} ${FT_PRINTF} > /dev/null 2>&1 && printf "\e[1;31m.\e[0m"

fclean: clean
	@${RM} ${NAME} ${FT_PRINTF} ${MLX}  > /dev/null 2>&1 && printf "\e[1;31m.\e[0m"

re: fclean all

.PHONY: all _bonus clean fclean re
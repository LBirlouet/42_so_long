/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:19:31 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/14 19:23:48 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>

# include "../srcs_bonus/gnl42/get_next_line.h"

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_ESCAPE	53

typedef struct s_colectible {
	int		colectible_count;
}				t_colectible;

typedef struct s_enemy {
	int		enemy_count;
}				t_enemy;

typedef struct s_exit {
	int		exit_count;
	int		exit_x;
	int		exit_y;
}				t_exit;

typedef struct s_player {
	int		rotation;
	int		player_count;
	int		player_x;
	int		player_y;
}				t_player;

typedef struct s_wall {
	int		wall_count;
}				t_wall;

typedef struct s_map_element {
	t_exit			exit;
	t_colectible	colectible;
	t_player		player;
	t_wall			wall;
	t_enemy			enemy;
}				t_map_element;

typedef struct s_img_path {
	char	*path_back;
	char	*path_wall;
	char	*path_exit;
	char	*path_player_top;
	char	*path_player_bot;
	char	*path_player_left;
	char	*path_player_right;
	char	*path_collectible;	
	char	*path_win;
	char	*path_wintxt;
	char	*path_loose;
	char	*path_loosetxt;	
	char	*path_enemy;
	char	*path_redheart;
	char	*path_deadheart;
	char	*path_display_score;
}				t_img_path;

typedef struct s_img {
	void		*imgback;
	void		*imgwall;
	void		*imgplayer_top;
	void		*imgplayer_bot;
	void		*imgplayer_left;
	void		*imgplayer_right;
	void		*imgexit;
	void		*imgcollectible;	
	void		*imgwin;
	void		*imgwintxt;
	void		*imgloose;
	void		*imgloosetxt;
	void		*imgenemy;
	void		*imgredheart;
	void		*imgdeadheart;
	void		*imgdisplay_score;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_img_path	path;
}				t_img;

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_map {
	char	*map_name;
	int		map_fd;
	int		map_x;
	int		map_y;
	char	**map;
}				t_map;

typedef struct s_verif {
	int		colectible_verif;
	char	**map_verif;
}				t_verif;

typedef struct s_so_long {
	t_map_element	element;
	t_img			img;
	t_mlx			mlx;
	t_map			map;
	t_verif			verif;
	int				status;
	int				heart;
	int				move_nbr;
	int				anim_x;
	int				anim_y;
	int				anim_dir;
	int				anim_speed;
	int				back_anim_x;
	int				back_anim_y;
}				t_so_long;

int		close_window(int keycode, t_so_long *t_so_long);
int		collectible_update(t_so_long *t_so_long);
int		copy_map(t_so_long *t_so_long);
int		display(t_so_long *t_so_long);
int		display_back(t_so_long *t_so_long);
int		display_collectible(t_so_long *t_so_long);
void	display_collectible_nbr(t_so_long *t_so_long);
int		display_enemy(t_so_long *t_so_long);
int		display_exit(t_so_long *t_so_long);
int		display_fix(t_so_long *t_so_long, int rotation);
int		display_heart(t_so_long *t_so_long);
void	display_heart0(t_so_long *t_so_long);
void	display_heart1(t_so_long *t_so_long);
void	display_heart2(t_so_long *t_so_long);
void	display_loose(t_so_long *t_so_long);
int		display_loose_anim(t_so_long *t_so_long);
void	display_move_nbr(t_so_long *t_so_long);
int		display_player(t_so_long *t_so_long, int rotation);
int		display_score(t_so_long *t_so_long);
int		display_wall(t_so_long *t_so_long);
void	display_win(t_so_long *t_so_long);
int		display_win_anim(t_so_long *t_so_long);
int		element_verif(t_so_long *t_so_long);
int		error_msg(void);
int		escape(int keycode, t_so_long *t_so_long);
void	exit_count_pos(t_so_long *t_so_long, int i, int line_counter);
int		fill_map(t_so_long *t_so_long);
int		fill_map_verif(t_so_long *t_so_long);
void	fillpaths(t_so_long *t_so_long, int row, int col);
int		free_all_exit(t_so_long *t_so_long);
int		ft_strlen_before_newline(char *str);
char	*ft_itoa(int n);
int		handle_key_press(int keycode, t_so_long *t_so_long);
void	init_verif_map(t_so_long *t_so_long);
int		main(int argc, char **argv);
int		malloc_map(t_so_long *t_so_long);
int		malloc_map_error_msg(void);
int		move(int keycode, t_so_long *t_so_long);
int		move_down(t_so_long *t_so_long);
int		move_left(t_so_long *t_so_long);
int		move_right(t_so_long *t_so_long);
int		move_up(t_so_long *t_so_long);
void	new_image(t_so_long *t_so_long);
void	new_image2(t_so_long *t_so_long);
void	path(t_so_long *t_so_long);
void	player_count_pos(t_so_long *t_so_long, int i, int line_counter);
int		possible_loose(t_so_long *t_so_long);
void	possible_loose_rotation(t_so_long *t_so_long);
int		possible_win(t_so_long *t_so_long);
int		ret_free_line(char *line);
int		return_free_map_verif(t_so_long *t_so_long, int tab_nbr, int ret);
void	update_animation(t_so_long *t_so_long);
int		verif_arg(int argc, char *str);
int		verif_first_line(char *map);
int		verif_gnl_wall_left_right(t_so_long *t_so_long, int side);
int		verif_last_line(int line_counter, t_so_long *t_so_long, int verif,
			int i);
int		verif_line(char *map, int line_size, t_so_long *t_so_long,
			int line_counter);
int		verif_map(t_so_long *t_so_long, int line_counter, int line_size,
			int verif);
int		verif_map2(t_so_long *t_so_long, int line_size, int line_counter);
int		verif_map_possible(t_so_long *t_so_long);
int		verif_recursive(t_so_long *t_so_long);
int		verif_wall(t_so_long *t_so_long, int side, int x);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:19:31 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/12 14:03:29 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../Minilibx/minilibx_opengl_20191021/mlx.h"
# include <fcntl.h>

# include "../srcs/gnl42/get_next_line.h"

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
	char	*path_loose;
	char	*path_enemy;
}				t_img_path;

typedef struct s_img {
	void	*imgback;
	void	*imgwall;
	void	*imgplayer_top;
	void	*imgplayer_bot;
	void	*imgplayer_left;
	void	*imgplayer_right;
	void	*imgexit;
	void	*imgcollectible;	
	void	*imgwin;
	void	*imgloose;
	void	*imgenemy;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
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

typedef struct s_so_long {
	t_map_element	element;
	t_img			img;
	t_mlx			mlx;
	t_map			map;
}				t_so_long;

int 	main(int argc, char **argv);
int		display(t_so_long *t_so_long);

int		display_fix(t_so_long *t_so_long, int rotation);
int		display_back(t_so_long *t_so_long);
int		display_wall(t_so_long *t_so_long);
int		display_exit(t_so_long *t_so_long);
int		display_player(t_so_long *t_so_long, int rotation);
int		display_collectible(t_so_long *t_so_long);
int		display_enemy(t_so_long *t_so_long);
void	display_win(t_so_long *t_so_long);
void	display_loose(t_so_long *t_so_long);

int		collectible_update(t_so_long *t_so_long);
int		possible_loose(t_so_long *t_so_long);

int		verif_wall(t_so_long *t_so_long, int side);
int		escape(int keycode, t_so_long *t_so_long);
void close_window(void *mlx_ptr, void *win_ptr);

/*move fonctions*/
int		moove(int keycode, t_so_long *t_so_long);
int		handle_key_press(int keycode, t_so_long *t_so_long);
int		moove_down(t_so_long *t_so_long);
int		moove_up(t_so_long *t_so_long);
int		moove_left(t_so_long *t_so_long);
int		moove_right(t_so_long *t_so_long);



int	probable_win(t_so_long *t_so_long);

void	path(t_so_long *t_so_long);
void	new_image(t_so_long *t_so_long);
//static int	ft_strlen(char *str);

/*map verif*/
int 	verif_map(t_so_long *t_so_long);
int		element_verif(t_so_long *t_so_long);
int		verif_line(char *map, int line_size, t_so_long *t_so_long, int line_counter);
int		verif_first_line(char *map);
int		verif_last_line(int line_counter, t_so_long *t_so_long);
int 	verif_gnl_wall_left_right(t_so_long *t_so_long, int side);



/*malloc and fill map*/
int malloc_map(t_so_long *t_so_long);
int	fill_map(t_so_long *t_so_long);

/*utils*/
int	ft_strlen_before_newline(char *str);


#endif
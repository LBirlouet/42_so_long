/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:19:31 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/11 17:17:40 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <mlx.h>
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
	int		wall_x;
	int		wall_y;
	
}				t_wall;

typedef struct s_map_element {
	t_exit			exit;
	t_colectible	colectible;
	t_player		player;
	t_wall			wall;
}				t_map_element;

typedef struct s_img_path {
	char	*path_back;
	char	*path_wall;
	char	*path_exit;
	char	*path_player_top;
	char	*path_player_bot;
	char	*path_player_left;
	char	*path_player_right;
	char	*path_win;
}				t_img_path;

typedef struct s_img {
	void	*imgback;
	void	*imgwall;
	void	*imgplayer_top;
	void	*imgplayer_bot;
	void	*imgplayer_left;
	void	*imgplayer_right;
	void	*imgexit;
	void	*imgwin;
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
}				t_map;

typedef struct s_so_long {
	t_map_element	element;
	t_img			img;
	t_mlx			mlx;
	t_map			map;
}				t_so_long;

int 	main(void);
int		display(t_so_long *t_so_long);

int		display_fix(t_so_long *t_so_long, int rotation);
int		display_back(t_so_long *t_so_long);
int		display_wall(t_so_long *t_so_long);
int		display_exit(t_so_long *t_so_long);
int		display_player(t_so_long *t_so_long, int rotation);

int		handle_key_press(int keycode, t_so_long *t_so_long);
int		moove(int keycode, t_so_long *t_so_long);
int		escape(int keycode, t_so_long *t_so_long);

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




/*utils*/
int	ft_strlen_before_newline(char *str);


#endif
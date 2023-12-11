/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:19:31 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/11 08:49:27 by lbirloue         ###   ########.fr       */
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

# define KEY_UP 
# define KEY_DOWN 125
# define KEY_LEFT
# define KEY_RIGHT
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

typedef struct s_map_element {
	t_exit			exit;
	t_colectible	colectible;
	t_player		player;
}				t_map_element;

typedef struct s_img_path {
	char	*path_back;
	char	*path_wall;
	char	*path_exit;
	char	*path_player_top;
}				t_img_path;

typedef struct s_img {
	void	*imgback;
	void	*imgwall;
	void	*imgplayer_top;
	void	*imgexit;
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


int 	main(void);
int		display(t_map *t_map, t_map_element *t_map_element);

int	display_fix(t_map *t_map, t_img t_img, t_mlx t_mlx, t_map_element t_map_element);

int		display_back(t_map *t_map, t_mlx *t_mlx, t_img *t_img);
int		display_wall(t_map *t_map, t_mlx *t_mlx, t_img *t_img);
int		display_exit(t_mlx *t_mlx, t_img *t_img, t_map_element t_map_element);
int		display_player(t_mlx *t_mlx, t_img *t_img, t_map_element t_map_element);

int	handle_key_press(int keycode, t_mlx *t_mlx, t_img t_img, t_map_element *t_map_element);

void	path(t_img *t_img);
void	new_image(void *mlx, t_map t_map, t_img *t_img);
//static int	ft_strlen(char *str);

/*map verif*/
int 	verif_map(t_map *t_map, t_map_element *t_map_element);
int		element_verif(t_map_element t_map_element);
int		verif_line(char *map, int line_size, t_map_element *t_map_element, int line_counter);
int		verif_first_line(char *map);
int		verif_last_line(int line_counter, t_map *t_map);




/*utils*/
int	ft_strlen_before_newline(char *str);


#endif
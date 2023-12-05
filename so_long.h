/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:19:31 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/05 10:41:53 by lbirloue         ###   ########.fr       */
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

# include "gnl42/get_next_line.h"

typedef struct s_colectible {
	int		colectible_count;
}				t_colectible;

typedef struct s_exit {
	int		exit_count;
}				t_exit;

typedef struct s_data {
	void	*imgback;
	void	*imgbackr;
	void	*imgbackrr;
	void	*imgbackrrr;
	void	*imgwall;
	char	*addr;
	char	*addr_wall;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map {
	char	*map_name;
	int		map_fd;
	int		map_x;
	int		map_y;
}				t_map;


// typedef struct	destroy {
// 	int		destroy_top_x;
// 	int		destroy_top_y;
// }				t_data;


int main(void);
int	display_back(t_map *t_map);
int	display_wall(t_map *t_map, void *mlx, t_data *img, void *mlx_win);
//static int	ft_strlen(char *str);

/*map verif*/
int verif_map(int fd, t_map *t_map, char *map_name);
int	verif_line(char *map, int line_size, t_colectible *t_colectible, t_exit *t_exit);
int verif_first_line(char *map);
int	verif_last_line(int line_counter, char *map_name, t_map *t_map);

/*utils*/
int	ft_strlen_before_newline(char *str);


#endif
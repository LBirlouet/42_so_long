/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:08:15 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/11 17:25:40 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	path(t_so_long *t_so_long)
{
	t_so_long->img.path.path_back = "./img/fond.xpm";
	t_so_long->img.path.path_wall = "./img/wall.xpm";
	t_so_long->img.path.path_exit = "./img/exit.xpm";
	t_so_long->img.path.path_player_top = "./img/player_top.xpm";
	t_so_long->img.path.path_player_bot = "./img/player_bot.xpm";
	t_so_long->img.path.path_player_left = "./img/player_left.xpm";
	t_so_long->img.path.path_player_right = "./img/player_right.xpm";

	t_so_long->img.path.path_player_right = "./img/win_test.xpm";


	return ;
}

void	new_image(t_so_long *t_so_long)
{
	int		img_width;
	int		img_height;

	t_so_long->img.imgback = mlx_new_image(t_so_long->mlx.mlx, (t_so_long->map.map_x * 100), (t_so_long->map.map_y * 100));
	t_so_long->img.imgwall = mlx_new_image(t_so_long->mlx.mlx, (t_so_long->map.map_x * 100), (t_so_long->map.map_x * 100));
	t_so_long->img.imgexit = mlx_new_image(t_so_long->mlx.mlx, (t_so_long->map.map_x * 100), (t_so_long->map.map_x * 100));
	t_so_long->img.imgplayer_top = mlx_new_image(t_so_long->mlx.mlx, (t_so_long->map.map_x * 100), (t_so_long->map.map_x * 100));
	t_so_long->img.imgplayer_bot = mlx_new_image(t_so_long->mlx.mlx, (t_so_long->map.map_x * 100), (t_so_long->map.map_x * 100));
	t_so_long->img.imgplayer_left = mlx_new_image(t_so_long->mlx.mlx, (t_so_long->map.map_x * 100), (t_so_long->map.map_x * 100));
	t_so_long->img.imgplayer_right = mlx_new_image(t_so_long->mlx.mlx, (t_so_long->map.map_x * 100), (t_so_long->map.map_x * 100));
	
	t_so_long->img.imgwin = mlx_new_image(t_so_long->mlx.mlx, 128, 128);
	t_so_long->img.imgwin = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_win, &img_width, &img_height);

	t_so_long->img.imgback = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_back, &img_width, &img_height);
	t_so_long->img.imgwall = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_wall, &img_width, &img_height);
	t_so_long->img.imgexit = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_exit, &img_width, &img_height);
	t_so_long->img.imgplayer_top = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_player_top, &img_width, &img_height);
	t_so_long->img.imgplayer_bot = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_player_bot, &img_width, &img_height);
	t_so_long->img.imgplayer_left = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_player_left, &img_width, &img_height);
	t_so_long->img.imgplayer_right = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_player_right, &img_width, &img_height);

	return ;
}

int		ft_strlen_before_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
	return (i);
}

// int verif_gnl_wall_left_right(t_so_long *t_so_long, int side)
// {
// 	int i;
// 	char *line;

// 	i = 0;
// 	t_so_long->map.map_fd = open(t_so_long->map.map_name, O_RDONLY, 0644);
// 	if (side == 6)
// 	{
// 		printf("%d\n", t_so_long->element.player.player_x);
// 		while (i < t_so_long->element.player.player_x)
// 		{
// 			line = get_next_line(t_so_long->map.map_fd);
// 			printf("ouai %s\n", line);
// 			free(line);
// 			i++;
// 		}
// 		if (line[t_so_long->element.player.player_x - 1] == '1')
// 			return (-1);
// 		else
// 			return (0);
// 	}
// 	close(t_so_long->map.map_fd);
// 	return (0);
// }


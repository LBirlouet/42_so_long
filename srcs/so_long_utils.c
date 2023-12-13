/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:08:15 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/13 10:25:29 by lbirloue         ###   ########.fr       */
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
	t_so_long->img.path.path_collectible = "./img/collectible.xpm";


	t_so_long->img.path.path_win = "./img/win_test.xpm";
	t_so_long->img.path.path_wintxt = "./img/wintxt.xpm";
	t_so_long->img.path.path_loose = "./img/looseskull.xpm";
	t_so_long->img.path.path_loosetxt = "./img/loose200x200.xpm";
	t_so_long->img.path.path_enemy = "./img/enemy.xpm";
	t_so_long->img.path.path_redheart = "./img/heartred.xpm";
	t_so_long->img.path.path_deadheart = "./img/heartdead.xpm";


	return ;
}

void	new_image(t_so_long *t_so_long)
{
	int		img_width;
	int		img_height;

	// t_so_long->img.imgback = mlx_new_image(t_so_long->mlx.mlx, (t_so_long->map.map_x * 100), (t_so_long->map.map_y * 100));
	// t_so_long->img.imgwall = mlx_new_image(t_so_long->mlx.mlx, (t_so_long->map.map_x * 100), (t_so_long->map.map_x * 100));
	// t_so_long->img.imgexit = mlx_new_image(t_so_long->mlx.mlx, (t_so_long->map.map_x * 100), (t_so_long->map.map_x * 100));
	// t_so_long->img.imgplayer_top = mlx_new_image(t_so_long->mlx.mlx, (t_so_long->map.map_x * 100), (t_so_long->map.map_x * 100));
	// t_so_long->img.imgplayer_bot = mlx_new_image(t_so_long->mlx.mlx, (t_so_long->map.map_x * 100), (t_so_long->map.map_x * 100));
	// t_so_long->img.imgplayer_left = mlx_new_image(t_so_long->mlx.mlx, (t_so_long->map.map_x * 100), (t_so_long->map.map_x * 100));
	// t_so_long->img.imgplayer_right = mlx_new_image(t_so_long->mlx.mlx, (t_so_long->map.map_x * 100), (t_so_long->map.map_x * 100));
	// t_so_long->img.imgcollectible = mlx_new_image(t_so_long->mlx.mlx, (t_so_long->map.map_x * 100), (t_so_long->map.map_x * 100));
	

	// t_so_long->img.imgwin = mlx_new_image(t_so_long->mlx.mlx, 128, 128);
	// t_so_long->img.imgloose = mlx_new_image(t_so_long->mlx.mlx, 128, 128);
	// t_so_long->img.imgenemy = mlx_new_image(t_so_long->mlx.mlx, 128, 128);

	t_so_long->img.imgwin = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_win, &img_width, &img_height);
	t_so_long->img.imgwintxt = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_wintxt, &img_width, &img_height);
	t_so_long->img.imgloose = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_loose, &img_width, &img_height);
	t_so_long->img.imgenemy = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_enemy, &img_width, &img_height);
	t_so_long->img.imgloosetxt = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_loosetxt, &img_width, &img_height);
	t_so_long->img.imgredheart = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_redheart, &img_width, &img_height);
	t_so_long->img.imgdeadheart = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_deadheart, &img_width, &img_height);


	t_so_long->img.imgback = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_back, &img_width, &img_height);
	t_so_long->img.imgwall = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_wall, &img_width, &img_height);
	t_so_long->img.imgexit = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_exit, &img_width, &img_height);
	t_so_long->img.imgplayer_top = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_player_top, &img_width, &img_height);
	t_so_long->img.imgplayer_bot = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_player_bot, &img_width, &img_height);
	t_so_long->img.imgplayer_left = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_player_left, &img_width, &img_height);
	t_so_long->img.imgplayer_right = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_player_right, &img_width, &img_height);
	t_so_long->img.imgcollectible = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_collectible, &img_width, &img_height);


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

int	copy_map(t_so_long *t_so_long)
{
	int i;
	int verif;
	
	i = 0;
	t_so_long->verif.map_verif = malloc(sizeof(char*) * (t_so_long->map.map_y + 1));
	if (!t_so_long->verif.map_verif)
		return (-1);
	while(i <= t_so_long->map.map_y)
	{
		t_so_long->verif.map_verif[i] = malloc(sizeof(char) * (t_so_long->map.map_x + 2));
		if (!t_so_long->verif.map_verif[i])
			return (-1);
		i++;
	}
	verif = fill_map_verif(t_so_long);
	return (0);
}

int	fill_map_verif(t_so_long *t_so_long)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= t_so_long->map.map_y)
	{
		j = 0;
		while (j <= t_so_long->map.map_x)
		{
			t_so_long->verif.map_verif[i][j] = t_so_long->map.map[i][j];
			j++;
		}
		t_so_long->verif.map_verif[i][j] = '\0';
		i++;
	}
	return (0);
}

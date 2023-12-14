/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:41:48 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/14 13:59:40 by lbirloue         ###   ########.fr       */
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
	t_so_long->img.path.path_display_score = "./img/display_score.xpm";
	return ;
}

void	new_image(t_so_long *t_so_long)
{
	int	img_width;
	int	img_height;

	t_so_long->img.imgwin = mlx_xpm_file_to_image(t_so_long->mlx.mlx,
			t_so_long->img.path.path_win, &img_width, &img_height);
	t_so_long->img.imgwintxt = mlx_xpm_file_to_image(t_so_long->mlx.mlx,
			t_so_long->img.path.path_wintxt, &img_width, &img_height);
	t_so_long->img.imgloose = mlx_xpm_file_to_image(t_so_long->mlx.mlx,
			t_so_long->img.path.path_loose, &img_width, &img_height);
	t_so_long->img.imgenemy = mlx_xpm_file_to_image(t_so_long->mlx.mlx,
			t_so_long->img.path.path_enemy, &img_width, &img_height);
	t_so_long->img.imgloosetxt = mlx_xpm_file_to_image(t_so_long->mlx.mlx,
			t_so_long->img.path.path_loosetxt, &img_width, &img_height);
	t_so_long->img.imgredheart = mlx_xpm_file_to_image(t_so_long->mlx.mlx,
			t_so_long->img.path.path_redheart, &img_width, &img_height);
	t_so_long->img.imgdeadheart = mlx_xpm_file_to_image(t_so_long->mlx.mlx,
			t_so_long->img.path.path_deadheart, &img_width, &img_height);
	t_so_long->img.imgdisplay_score = mlx_xpm_file_to_image(t_so_long->mlx.mlx,
			t_so_long->img.path.path_display_score, &img_width, &img_height);
	new_image2(t_so_long);
	return ;
}

void	new_image2(t_so_long *t_so_long)
{
	int	img_width;
	int	img_height;

	t_so_long->img.imgback = mlx_xpm_file_to_image(t_so_long->mlx.mlx,
			t_so_long->img.path.path_back, &img_width, &img_height);
	t_so_long->img.imgwall = mlx_xpm_file_to_image(t_so_long->mlx.mlx,
			t_so_long->img.path.path_wall, &img_width, &img_height);
	t_so_long->img.imgexit = mlx_xpm_file_to_image(t_so_long->mlx.mlx,
			t_so_long->img.path.path_exit, &img_width, &img_height);
	t_so_long->img.imgplayer_top = mlx_xpm_file_to_image(t_so_long->mlx.mlx,
			t_so_long->img.path.path_player_top, &img_width, &img_height);
	t_so_long->img.imgplayer_bot = mlx_xpm_file_to_image(t_so_long->mlx.mlx,
			t_so_long->img.path.path_player_bot, &img_width, &img_height);
	t_so_long->img.imgplayer_left = mlx_xpm_file_to_image(t_so_long->mlx.mlx,
			t_so_long->img.path.path_player_left, &img_width, &img_height);
	t_so_long->img.imgplayer_right = mlx_xpm_file_to_image(t_so_long->mlx.mlx,
			t_so_long->img.path.path_player_right, &img_width, &img_height);
	t_so_long->img.imgcollectible = mlx_xpm_file_to_image(t_so_long->mlx.mlx,
			t_so_long->img.path.path_collectible, &img_width, &img_height);
	return ;
}

void	exit_count_pos(t_so_long *t_so_long, int i, int line_counter)
{
	t_so_long->element.exit.exit_count++;
	t_so_long->element.exit.exit_x = i;
	t_so_long->element.exit.exit_y = line_counter;
	return ;
}

void	player_count_pos(t_so_long *t_so_long, int i, int line_counter)
{
	t_so_long->element.player.player_x = i;
	t_so_long->element.player.player_count++;
	t_so_long->element.player.player_y = line_counter;
	return ;
}

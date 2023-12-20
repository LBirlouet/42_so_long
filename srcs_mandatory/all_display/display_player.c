/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:03:45 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/14 18:44:07 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	display_player(t_so_long *t_so_long, int rotation)
{
	if (rotation == 8)
		mlx_put_image_to_window(t_so_long->mlx.mlx,
			t_so_long->mlx.mlx_win, t_so_long->img.imgplayer_top,
			(t_so_long->element.player.player_x * 100),
			(t_so_long->element.player.player_y * 100));
	else if (rotation == 2)
		mlx_put_image_to_window(t_so_long->mlx.mlx,
			t_so_long->mlx.mlx_win, t_so_long->img.imgplayer_bot,
			(t_so_long->element.player.player_x * 100),
			(t_so_long->element.player.player_y * 100));
	else if (rotation == 4)
		mlx_put_image_to_window(t_so_long->mlx.mlx,
			t_so_long->mlx.mlx_win, t_so_long->img.imgplayer_left,
			(t_so_long->element.player.player_x * 100),
			(t_so_long->element.player.player_y * 100));
	else if (rotation == 6)
		mlx_put_image_to_window(t_so_long->mlx.mlx,
			t_so_long->mlx.mlx_win, t_so_long->img.imgplayer_right,
			(t_so_long->element.player.player_x * 100),
			(t_so_long->element.player.player_y * 100));
	return (0);
}

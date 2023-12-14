/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:15:21 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/14 18:44:07 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	possible_loose(t_so_long *t_so_long)
{
	int	i;
	int	j;

	i = t_so_long->element.player.player_x;
	j = t_so_long->element.player.player_y;
	if (t_so_long->map.map[j][i] == '!' && t_so_long->heart != 0)
	{
		possible_loose_rotation(t_so_long);
		display_fix(t_so_long, t_so_long->element.player.rotation);
		return (display_collectible(t_so_long));
	}
	if (t_so_long->map.map[j][i] == '!' && t_so_long->heart == 0)
	{
		t_so_long->anim_x = (t_so_long->map.map_x / 2);
		t_so_long->anim_y = (t_so_long->map.map_y / 2);
		mlx_loop_hook(t_so_long->mlx.mlx,
			(int (*)(void *))display_loose_anim, t_so_long);
		t_so_long->status = 1;
	}
	return (0);
}

int	possible_win(t_so_long *t_so_long)
{
	if ((t_so_long->element.player.player_x == t_so_long->element.exit.exit_x)
		&& (t_so_long->element.player.player_y 
			== t_so_long->element.exit.exit_y)
		&& (t_so_long->element.colectible.colectible_count == 0))
	{
		mlx_clear_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win);
		t_so_long->anim_x = (t_so_long->map.map_x / 2);
		t_so_long->anim_y = (t_so_long->map.map_y / 2);
		mlx_loop_hook(t_so_long->mlx.mlx,
			(int (*)(void *))display_win_anim, t_so_long);
		t_so_long->status = 1;
	}
	return (0);
}

void	possible_loose_rotation(t_so_long *t_so_long)
{
	t_so_long->heart--;
	if (t_so_long->element.player.rotation == 4)
		t_so_long->element.player.player_x += 1;
	else if (t_so_long->element.player.rotation == 6)
		t_so_long->element.player.player_x -= 1;
	else if (t_so_long->element.player.rotation == 2)
		t_so_long->element.player.player_y -= 1;
	else if (t_so_long->element.player.rotation == 8)
		t_so_long->element.player.player_y += 1;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:11:42 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/13 19:22:11 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	display(t_so_long *t_so_long)
{
	int	verif;

	path(t_so_long);
	t_so_long->moove_nbr = 0;
	t_so_long->mlx.mlx = mlx_init();
	t_so_long->mlx.mlx_win = mlx_new_window(t_so_long->mlx.mlx,
			(t_so_long->map.map_x * 100), ((t_so_long->map.map_y + 1) * 100),
			"so_long");
	new_image(t_so_long);
	t_so_long->status = 0;
	verif = display_fix(t_so_long, 8);
	verif = display_collectible(t_so_long);
	mlx_hook(t_so_long->mlx.mlx_win, 2, 0, &handle_key_press, t_so_long);
	mlx_hook(t_so_long->mlx.mlx_win, 17, 0, &close_window, t_so_long);
	mlx_loop(t_so_long->mlx.mlx);
	return (0);
}

int	display_fix(t_so_long *t_so_long, int rotation)
{
	int	verif ;

	verif = display_back(t_so_long);
	verif = display_wall(t_so_long);
	verif = display_exit(t_so_long);
	verif = display_enemy(t_so_long);
	verif = display_player(t_so_long, rotation);
	verif = display_heart(t_so_long);
	mlx_string_put(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
		0, 10, 0x00FF0000, "Moove :");
	mlx_string_put(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
		60, 10, 0x00FF0000, "0");
	return (verif);
}

int	collectible_update(t_so_long *t_so_long)
{
	int	x;
	int	y;

	x = t_so_long->element.player.player_x;
	y = t_so_long->element.player.player_y;
	if (t_so_long->map.map[y][x] == 'C')
	{
		t_so_long->element.colectible.colectible_count--;
		t_so_long->map.map[y][x] = '0';
	}
	return (0);
}

int	verif_wall(t_so_long *t_so_long, int side, int x)
{
	int	y;

	x = t_so_long->element.player.player_x;
	y = t_so_long->element.player.player_y;
	if (side == 8)
	{
		if (t_so_long->map.map[y - 1][x] == '1')
			return (-1);
	}
	if (side == 2)
	{
		if (t_so_long->map.map[y + 1][x] == '1')
			return (-1);
	}
	if (side == 6)
	{
		if (t_so_long->map.map[y][x + 1] == '1')
			return (-1);
	}
	if (side == 4)
	{
		if (t_so_long->map.map[y][x - 1] == '1')
			return (-1);
	}
	return (0);
}

int	escape(int keycode, t_so_long *t_so_long)
{
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window((void *)t_so_long->mlx.mlx,
			(void *)t_so_long->mlx.mlx_win);
		return (free_all_exit(t_so_long));
	}
	return (0);
}

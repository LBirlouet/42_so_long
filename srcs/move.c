/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:36:57 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/13 10:38:33 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_key_press(int keycode, t_so_long *t_so_long)
{
	int verif;
	if (t_so_long->status == 0)
	{
	verif = moove(keycode, t_so_long);
	verif = probable_win(t_so_long);
	printf("x = %d| y = %d\n", t_so_long->element.player.player_x, t_so_long->element.player.player_y);
	verif = possible_loose(t_so_long);
	}
	verif = escape(keycode, t_so_long);

	return (0);
}

int moove(int keycode, t_so_long *t_so_long)
{
	int verif;
	if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		verif = moove_down(t_so_long);
	}
	if (keycode == KEY_UP || keycode == KEY_W)
	{
		verif = moove_up(t_so_long);
	}
	if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		verif = moove_right(t_so_long);
	}
	if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		verif = moove_left(t_so_long);
	}
	verif = display_collectible(t_so_long);
	return (0);
}


int	moove_down(t_so_long *t_so_long)
{
	int verif;
	
	if ((t_so_long->element.player.player_y + 1) == t_so_long->map.map_y || verif_wall(t_so_long, 2) == -1)
	{
		mlx_clear_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win);
		t_so_long->element.player.rotation = 2;
		verif = display_fix(t_so_long, t_so_long->element.player.rotation);
		verif = display_collectible(t_so_long);
		return (0);
	}
	t_so_long->element.player.player_y += 1;
	t_so_long->moove_nbr++;
	ft_printf("Move : %d\n", t_so_long->moove_nbr);
	mlx_clear_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win);
	t_so_long->element.player.rotation = 2;
	verif = display_fix(t_so_long, t_so_long->element.player.rotation);
	verif = collectible_update(t_so_long);
	return (0);
}

int	moove_up(t_so_long *t_so_long)
{
	int verif;

	if (t_so_long->element.player.player_y == 1  || verif_wall(t_so_long, 8) == -1)
	{
		mlx_clear_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win);
		t_so_long->element.player.rotation = 8;		
		verif = display_fix(t_so_long, t_so_long->element.player.rotation);
		verif = display_collectible(t_so_long);
		return (0);
	}
	t_so_long->element.player.player_y -= 1;
	t_so_long->moove_nbr++;
	ft_printf("Move : %d\n", t_so_long->moove_nbr);
	mlx_clear_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win);
	t_so_long->element.player.rotation = 8;		
	verif = display_fix(t_so_long, t_so_long->element.player.rotation);
	verif = collectible_update(t_so_long);
	return (0);
}

int	moove_left(t_so_long *t_so_long)
{
	int verif;

	if (t_so_long->element.player.player_x == 1 || verif_wall(t_so_long, 4) == -1)
	{
		mlx_clear_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win);
		t_so_long->element.player.rotation = 4;	
		verif = display_fix(t_so_long, t_so_long->element.player.rotation);
		verif = display_collectible(t_so_long);
		return (0);
	}
	t_so_long->element.player.player_x -= 1;
	t_so_long->moove_nbr++;
	ft_printf("Move : %d\n", t_so_long->moove_nbr);
	mlx_clear_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win);
	t_so_long->element.player.rotation = 4;	
	verif = display_fix(t_so_long, t_so_long->element.player.rotation);
	verif = collectible_update(t_so_long);
	return (0);
}

int	moove_right(t_so_long *t_so_long)
{
	int verif;

	if ((t_so_long->element.player.player_x + 2)== t_so_long->map.map_x || verif_wall(t_so_long, 6) == -1)
	{
		mlx_clear_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win);
		t_so_long->element.player.rotation = 6;	
		verif = display_fix(t_so_long, t_so_long->element.player.rotation);
		verif = display_collectible(t_so_long);
		return (0);
	}
	t_so_long->element.player.player_x += 1;
	t_so_long->moove_nbr++;
	ft_printf("Move : %d\n", t_so_long->moove_nbr);
	mlx_clear_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win);
	t_so_long->element.player.rotation = 6;	
	verif = display_fix(t_so_long, t_so_long->element.player.rotation);
	verif = collectible_update(t_so_long);
	return (0);
}




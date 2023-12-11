/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:11:42 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/11 17:23:48 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	display(t_so_long *t_so_long)
{
	int		verif;

	path(t_so_long);
	t_so_long->mlx.mlx = mlx_init();
	t_so_long->mlx.mlx_win = mlx_new_window(t_so_long->mlx.mlx, (t_so_long->map.map_x * 100),
			((t_so_long->map.map_y + 1) * 100), "so_long");
	new_image(t_so_long);

	verif = display_fix(t_so_long, 8);
	mlx_hook(t_so_long->mlx.mlx_win, 2,0, &handle_key_press, t_so_long);
	mlx_loop(t_so_long->mlx.mlx);
	return (0);
}

int	display_fix(t_so_long *t_so_long, int rotation)
{
	int verif ;

	verif = display_back(t_so_long);
	verif = display_wall(t_so_long);
	verif = display_exit(t_so_long);
	verif = display_player(t_so_long, rotation);
	return (verif);
}

int	display_player(t_so_long *t_so_long, int rotation)
{
	if (rotation == 8)
		mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win, t_so_long->img.imgplayer_top,
			(t_so_long->element.player.player_x * 100), (t_so_long->element.player.player_y
				* 100));
	else if (rotation == 2)
		mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win, t_so_long->img.imgplayer_bot,
			(t_so_long->element.player.player_x * 100), (t_so_long->element.player.player_y
				* 100));
	else if (rotation == 4)
		mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win, t_so_long->img.imgplayer_left,
			(t_so_long->element.player.player_x * 100), (t_so_long->element.player.player_y
				* 100));
	else if (rotation == 6)
		mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win, t_so_long->img.imgplayer_right,
			(t_so_long->element.player.player_x * 100), (t_so_long->element.player.player_y
				* 100));
	return (0);
}

int	display_exit(t_so_long *t_so_long)
{
	mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win, t_so_long->img.imgexit,
		(t_so_long->element.exit.exit_x * 100), (t_so_long->element.exit.exit_y * 100));
	return (0);
}

int	display_back(t_so_long *t_so_long)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= (t_so_long->map.map_y * 100))
	{
		x = 0;
		while (x <= (t_so_long->map.map_x * 100))
		{
			mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win, t_so_long->img.imgback,
				x, y);
			x += 100;
		}
		y += 100;
	}
	return (0);
}

int	display_wall(t_so_long *t_so_long)
{
	char	*line;
	int		x;
	int		y;
	int		fd;

	fd = open(t_so_long->map.map_name, O_RDONLY, 0644);
	if (fd == -1)
		return (1);
	y = 0;
	while (y <= t_so_long->map.map_y)
	{
		x = 0;
		line = get_next_line(fd);
		while (line[x] != '\n' && line[x] != 0)
		{
			if (line[x] == '1')
				mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
					t_so_long->img.imgwall, (x * 100), (y * 100));
			x++;
		}
		free(line);
		y++;
	}
	close(fd);
	return (0);
}
int moove(int keycode, t_so_long *t_so_long)
{
	int verif;
	if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		if ((t_so_long->element.player.player_y + 1)== t_so_long->map.map_y)
			return (0);
		t_so_long->element.player.player_y += 1;
		mlx_clear_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win);
		verif = display_fix(t_so_long, 2);
	}
	if (keycode == KEY_UP || keycode == KEY_W)
	{
		if (t_so_long->element.player.player_y == 1)
			return (0);
		t_so_long->element.player.player_y -= 1;
		mlx_clear_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win);
		verif = display_fix(t_so_long, 8);
	}
	if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		if (t_so_long->element.player.player_x == 1)
			return (0);
		t_so_long->element.player.player_x -= 1;
		mlx_clear_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win);
		verif = display_fix(t_so_long, 4);
	}
	if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		if ((t_so_long->element.player.player_x + 2)== t_so_long->map.map_x)
			return (0);
		// verif = verif_gnl_wall_left_right(t_so_long, 6);
		// if (verif == -1)
		// 	return (0);
		t_so_long->element.player.player_x += 1;
		mlx_clear_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win);
		verif = display_fix(t_so_long, 6);
	}
	return (0);
}

int	probable_win(t_so_long *t_so_long)
{
	if (t_so_long->element.player.player_x == t_so_long->element.exit.exit_x && t_so_long->element.player.player_y == t_so_long->element.exit.exit_y && t_so_long->element.colectible.colectible_count == 0)
	{
		mlx_clear_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win);
		printf("ui\n");
		mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win, t_so_long->img.imgwin,
			0, 0);
		printf("naaa\n");
	}
	return (0);
}


int	escape(int keycode, t_so_long *t_so_long)
{
	if (keycode == KEY_ESCAPE)
		{
		mlx_destroy_window((void *)t_so_long->mlx.mlx, (void *)t_so_long->mlx.mlx_win);
		exit(0);
	}
	return (0);
}

int	handle_key_press(int keycode, t_so_long *t_so_long)
{
	int verif;
	verif = moove(keycode, t_so_long);
	verif = escape(keycode, t_so_long);
	verif = probable_win(t_so_long);

	return (0);
	// Autres actions en fonction des touches pressées
}

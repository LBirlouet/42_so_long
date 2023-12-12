/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:11:42 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/12 17:32:07 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	display(t_so_long *t_so_long)
{
	int		verif;

	path(t_so_long);
	t_so_long->moove_nbr = 0;
	t_so_long->mlx.mlx = mlx_init();
	t_so_long->mlx.mlx_win = mlx_new_window(t_so_long->mlx.mlx, (t_so_long->map.map_x * 100),
			((t_so_long->map.map_y + 1) * 100), "so_long");
	new_image(t_so_long);
	t_so_long->status = 0;

//	mlx_string_put(t_so_long->mlx.mlx, t_so_long->mlx.mlx, 100, 100, 0x00FF66, "oui");
	verif = display_fix(t_so_long, 8);
	verif = display_collectible(t_so_long);

	
	mlx_hook(t_so_long->mlx.mlx_win, 2,0, &handle_key_press, t_so_long);
	mlx_hook(t_so_long->mlx.mlx_win, 17, 0, &close_window, t_so_long);
	mlx_loop(t_so_long->mlx.mlx);
	return (0);
}

int close_window(int keycode, t_so_long *t_so_long)
{
	(void) keycode;
	mlx_destroy_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win);
	exit(0);
}

int	display_collectible(t_so_long *t_so_long)
{
	int i;
	int j;
	
	i = 0;
	while (i <= t_so_long->map.map_y)
	{
		j = 0;
		while (t_so_long->map.map[i][j] == '1' || t_so_long->map.map[i][j] == '0' || t_so_long->map.map[i][j] == 'E' || t_so_long->map.map[i][j] == 'P' || t_so_long->map.map[i][j] == 'C' || t_so_long->map.map[i][j] == '!')
		{
			if (t_so_long->map.map[i][j] == 'C')
					mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win, t_so_long->img.imgcollectible,
						((j) * 100), ((i)* 100));
			j++;
		}
		i++;
	}
	return (0);
}

int	display_fix(t_so_long *t_so_long, int rotation)
{
	int verif ;

	verif = display_back(t_so_long);
	verif = display_wall(t_so_long);
	verif = display_exit(t_so_long);
	verif = display_enemy(t_so_long);
	verif = display_player(t_so_long, rotation);
	return (verif);
}

int	display_enemy(t_so_long *t_so_long)
{
	int i;
	int j;
	
	i = 0;
	while (i <= t_so_long->map.map_y)
	{
		j = 0;
		while (t_so_long->map.map[i][j] == '1' || t_so_long->map.map[i][j] == '!' || t_so_long->map.map[i][j] == '0' || t_so_long->map.map[i][j] == 'E' || t_so_long->map.map[i][j] == 'P' || t_so_long->map.map[i][j] == 'C')
		{
			if (t_so_long->map.map[i][j] == '!')
					mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win, t_so_long->img.imgenemy,
						(j * 100), ( i* 100));
			j++;
		}
		i++;
	}
	return (0);
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

int	collectible_update(t_so_long *t_so_long)
{
	int x;
	int y;

	x = t_so_long->element.player.player_x;
	y = t_so_long->element.player.player_y;
	if (t_so_long->map.map[y][x] == 'C')
	{
		t_so_long->element.colectible.colectible_count--;
		t_so_long->map.map[y][x] = '0';
	}
	return (0);
}

int	verif_wall(t_so_long *t_so_long, int side)
{
	int x;
	int y;
	
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
	return(0);
}

int	possible_loose(t_so_long *t_so_long)
{
	int i;
	int j;
	// printf("%s\n", t_so_long->map.map[1]);
	// printf("oui\n");
	i = t_so_long->element.player.player_x;
	j = t_so_long->element.player.player_y;
	// printf("%d | %d\n", i, j);
	if (t_so_long->map.map[j][i] == '!')
	{
	//	printf("vient\n");
		display_loose(t_so_long);
		t_so_long->status = 1;
		// printf("non %s\n", t_so_long->map.map[j]);
	//	mlx_destroy_window((void *)t_so_long->mlx.mlx, (void *)t_so_long->mlx.mlx_win);
	//	exit (0);
	}
	
	return (0);	
}

void	display_loose(t_so_long *t_so_long)
{
	int i;
	int j;

	i = 0;
	while (i <= t_so_long->map.map_y)
	{
		j = 0;
		while (j <= t_so_long->map.map_x)
		{
		//	printf("et ici ? \n");
			mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win, t_so_long->img.imgback, (j * 100), (i* 100));
			j++;
		}
		i++;
	}
//	printf("revient\n");
	
	mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win, t_so_long->img.imgloose, (((t_so_long->map.map_x - 2) *100) / 2), (((t_so_long->map.map_y - 3)* 100) / 2));
	mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win, t_so_long->img.imgloosetxt, (((t_so_long->map.map_x - 2) *100) / 2), (((t_so_long->map.map_y + 1 )* 100) / 2));
//	mlx_string_put(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,((t_so_long->map.map_x * 100)/2) , ((t_so_long->map.map_y * 100)/2), 0xfffafa, "YOU LOOSE !");
}

void	display_win(t_so_long *t_so_long)
{
	//int verif;
	int i;
	int j;

	i = 0;
//	printf("map X == %d\n", t_so_long->map.map_x);
//	printf("map X= %d| map y= %d\n", t_so_long->map.map_y, t_so_long->map.map_y);

	while (i <= t_so_long->map.map_y)
	{
		j = 0;
		while (j <= t_so_long->map.map_x)
		{
			mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win, t_so_long->img.imgback, (j * 100), (i* 100));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win, t_so_long->img.imgwin, (((t_so_long->map.map_x - 1) *100) / 2), (((t_so_long->map.map_y - 2)* 100) / 2));
	mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win, t_so_long->img.imgwintxt, (((t_so_long->map.map_x - 2) *100) / 2), (((t_so_long->map.map_y )* 100) / 2));
	t_so_long->status = 1;
//	mlx_destroy_window((void *)t_so_long->mlx.mlx, (void *)t_so_long->mlx.mlx_win);
//	exit(0);
	
}

int	probable_win(t_so_long *t_so_long)
{
	if ((t_so_long->element.player.player_x == t_so_long->element.exit.exit_x) && (t_so_long->element.player.player_y == t_so_long->element.exit.exit_y) && (t_so_long->element.colectible.colectible_count == 0))
	{
		mlx_clear_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win);
		display_win(t_so_long);
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


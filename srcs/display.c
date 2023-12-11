/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:11:42 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/11 08:53:31 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	display(t_map *t_map, t_map_element *t_map_element)
{
	int		verif;
	t_mlx	t_mlx;
	t_img	t_img;

	path(&t_img);
	t_mlx.mlx = mlx_init();
	t_mlx.mlx_win = mlx_new_window(t_mlx.mlx, (t_map->map_x * 32),
			((t_map->map_y + 1) * 32), "so_long");
	new_image(t_mlx.mlx, *t_map, &t_img);

	verif = display_fix(t_map, t_img, t_mlx, *t_map_element);
	printf("y avant fonction = %d\n", t_map_element->player.player_y);
	mlx_hook(t_mlx.mlx_win, 2, 1L << 0, &handle_key_press, (void *)&t_mlx);
	mlx_loop(t_mlx.mlx);
	return (0);
}

int	display_fix(t_map *t_map, t_img t_img, t_mlx t_mlx, t_map_element t_map_element)
{
	int verif ;

	verif = display_back(t_map, &t_mlx, &t_img);
	verif = display_wall(t_map, &t_mlx, &t_img);
	verif = display_exit(&t_mlx, &t_img, t_map_element);
	verif = display_player(&t_mlx, &t_img, t_map_element);
	return (verif);
}

int	display_player(t_mlx *t_mlx, t_img *t_img, t_map_element t_map_element)
{
	mlx_put_image_to_window(t_mlx->mlx, t_mlx->mlx_win, t_img->imgplayer_top,
		(t_map_element.player.player_x * 32), (t_map_element.player.player_count
			* 32));
	return (0);
}

int	display_exit(t_mlx *t_mlx, t_img *t_img, t_map_element t_map_element)
{
	mlx_put_image_to_window(t_mlx->mlx, t_mlx->mlx_win, t_img->imgexit,
		(t_map_element.exit.exit_x * 32), (t_map_element.exit.exit_y * 32));
	return (0);
}

int	display_back(t_map *t_map, t_mlx *t_mlx, t_img *t_img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= (t_map->map_y * 32))
	{
		x = 0;
		while (x <= (t_map->map_x * 32))
		{
			mlx_put_image_to_window(t_mlx->mlx, t_mlx->mlx_win, t_img->imgback,
				x, y);
			x += 32;
		}
		y += 32;
	}
	return (0);
}

int	display_wall(t_map *t_map, t_mlx *t_mlx, t_img *t_img)
{
	char	*line;
	int		x;
	int		y;
	int		fd;

	fd = open(t_map->map_name, O_RDONLY, 0644);
	if (fd == -1)
		return (1);
	y = 0;
	while (y <= t_map->map_y)
	{
		x = 0;
		line = get_next_line(fd);
		while (line[x] != '\n' && line[x] != 0)
		{
			if (line[x] == '1')
				mlx_put_image_to_window(t_mlx->mlx, t_mlx->mlx_win,
					t_img->imgwall, (x * 32), (y * 32));
			x++;
		}
		free(line);
		y++;
	}
	close(fd);
	return (0);
}

int	handle_key_press(int keycode, t_mlx *t_mlx, t_img t_img, t_map_element *t_map_element)
{
	printf("y dans fonction %d\n", t_map_element->player.player_y);
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(t_mlx->mlx, t_mlx->mlx_win);
		exit(0);
	}
	if (keycode == KEY_DOWN)
	{
		t_map_element->player.player_y = 5;
		t_map_element->player.player_x = 5;

		mlx_clear_window(t_mlx->mlx, t_mlx->mlx_win);
		mlx_put_image_to_window(t_mlx->mlx, t_mlx->mlx_win, t_img.imgplayer_top, (t_map_element->player.player_x * 32), (t_map_element->player.player_y * 32));
	}
	return (0);
	// Autres actions en fonction des touches pressées
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:11:42 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/05 19:12:20 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	display(t_map *t_map, t_map_element *t_map_element)
{
	int			verif;
	t_mlx		t_mlx;
	t_img		t_img;
	

	path(&t_img);
	t_mlx.mlx = mlx_init();
	t_mlx.mlx_win = mlx_new_window(t_mlx.mlx, (t_map->map_x * 32), ((t_map->map_y + 1) * 32), "so_long");
	new_image(t_mlx.mlx, *t_map, &t_img);

	verif = display_back(t_map, &t_mlx, &t_img);
	verif = display_wall(t_map, &t_mlx, &t_img);
	verif = display_exit(&t_mlx, &t_img, *t_map_element);

	mlx_loop(t_mlx.mlx);
	return (0);
}

int	display_exit(t_mlx *t_mlx, t_img *t_img, t_map_element t_map_element)
{
	mlx_put_image_to_window(t_mlx->mlx, t_mlx->mlx_win, t_img->imgexit, (t_map_element.exit.exit_x * 32), (t_map_element.exit.exit_y * 32));
	return (0);
}

int display_back(t_map *t_map, t_mlx *t_mlx, t_img *t_img)
{
	int x = 0;
	int y = 0;
	while (y <= (t_map->map_y * 32))
	{
		x = 0;
		while (x <= (t_map->map_x * 32))
		{
			mlx_put_image_to_window(t_mlx->mlx, t_mlx->mlx_win, t_img->imgback, x, y);
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

	int fd = open(t_map->map_name, O_RDONLY, 0644);
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
				mlx_put_image_to_window(t_mlx->mlx, t_mlx->mlx_win, t_img->imgwall, (x * 32), (y * 32));
			x++;
		}
		free(line);
		y++;
	}
	close(fd);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:08:15 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/11 09:30:14 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	path(t_so_long *t_so_long)
{
	t_so_long->img.path.path_back = "./img/fond32x32.xpm";
	t_so_long->img.path.path_wall = "./img/wall.xpm";
	t_so_long->img.path.path_player_top = "./img/player_top.xpm";
	t_so_long->img.path.path_exit = "./img/exit.xpm";
	return ;
}

void	new_image(t_so_long *t_so_long)
{
	int		img_width;
	int		img_height;

	t_so_long->img.imgback = mlx_new_image(t_so_long->mlx.mlx, (t_so_long->map.map_x * 32), (t_so_long->map.map_y * 32));
	t_so_long->img.imgwall = mlx_new_image(t_so_long->mlx.mlx, (t_so_long->map.map_x * 32), (t_so_long->map.map_x * 32));
	t_so_long->img.imgplayer_top = mlx_new_image(t_so_long->mlx.mlx, (t_so_long->map.map_x * 32), (t_so_long->map.map_x * 32));
	t_so_long->img.imgexit = mlx_new_image(t_so_long->mlx.mlx, (t_so_long->map.map_x * 32), (t_so_long->map.map_x * 32));
	
	t_so_long->img.imgback = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_back, &img_width, &img_height);
	t_so_long->img.imgwall = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_wall, &img_width, &img_height);
	t_so_long->img.imgplayer_top = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_player_top, &img_width, &img_height);
	t_so_long->img.imgexit = mlx_xpm_file_to_image(t_so_long->mlx.mlx, t_so_long->img.path.path_exit, &img_width, &img_height);
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


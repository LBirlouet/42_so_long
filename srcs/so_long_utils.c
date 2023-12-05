/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:08:15 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/05 19:05:23 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	path(t_img *t_img)
{
	t_img->path.path_back = "./img/fond32x32.xpm";
	t_img->path.path_wall = "./img/wall.xpm";
	t_img->path.path_player_top = "./img/player_top.xpm";
	t_img->path.path_exit = "./img/exit.xpm";
	return ;
}

void	new_image(void *mlx, t_map t_map, t_img *t_img)
{
	int		img_width;
	int		img_height;

	t_img->imgback = mlx_new_image(mlx, (t_map.map_x * 32), (t_map.map_y * 32));
	t_img->imgwall = mlx_new_image(mlx, (t_map.map_x * 32), (t_map.map_x * 32));
	t_img->imgplayer_top = mlx_new_image(mlx, (t_map.map_x * 32), (t_map.map_x * 32));
	t_img->imgexit = mlx_new_image(mlx, (t_map.map_x * 32), (t_map.map_x * 32));
	t_img->imgback = mlx_xpm_file_to_image(mlx, t_img->path.path_back, &img_width, &img_height);
	t_img->imgwall = mlx_xpm_file_to_image(mlx, t_img->path.path_wall, &img_width, &img_height);
	t_img->imgplayer_top = mlx_xpm_file_to_image(mlx, t_img->path.path_player_top, &img_width, &img_height);
	t_img->imgexit = mlx_xpm_file_to_image(mlx, t_img->path.path_exit, &img_width, &img_height);
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


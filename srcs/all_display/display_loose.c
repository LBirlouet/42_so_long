/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_loose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:10:40 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/13 18:43:19 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	display_loose(t_so_long *t_so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i <= t_so_long->map.map_y)
	{
		j = 0;
		while (j <= t_so_long->map.map_x)
		{
			mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
				t_so_long->img.imgback, (j * 100), (i * 100));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
		t_so_long->img.imgloose, (((t_so_long->map.map_x - 2) * 100) / 2),
		(((t_so_long->map.map_y - 3) * 100) / 2));
	mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
		t_so_long->img.imgloosetxt, (((t_so_long->map.map_x - 2) * 100) / 2),
		(((t_so_long->map.map_y + 1) * 100) / 2));
}

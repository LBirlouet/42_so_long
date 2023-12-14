/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_loose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:10:40 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/14 18:44:07 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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
		t_so_long->img.imgloose,
		(((t_so_long->map.map_x - 2) * 100) / 2) + t_so_long->anim_x,
		(((t_so_long->map.map_y - 3) * 100) / 2) + t_so_long->anim_y);
	mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
		t_so_long->img.imgloosetxt,
		(((t_so_long->map.map_x - 2) * 100) / 2) + t_so_long->anim_x,
		(((t_so_long->map.map_y + 1) * 100) / 2) + t_so_long->anim_y);
}

int	display_loose_anim(t_so_long *t_so_long)
{
	t_so_long->anim_y += t_so_long->anim_dir * t_so_long->anim_speed;
	if (t_so_long->anim_y <= 0 || t_so_long->anim_y >= 100)
		t_so_long->anim_dir *= -1;
	display_loose(t_so_long);
	return (0);
}

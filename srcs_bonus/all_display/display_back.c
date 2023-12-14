/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:00:43 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/14 18:43:32 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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
			mlx_put_image_to_window(t_so_long->mlx.mlx,
				t_so_long->mlx.mlx_win, t_so_long->img.imgback,
				x, y);
			x += 100;
		}
		y += 100;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_heart.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:07:31 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/14 18:44:07 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	display_heart(t_so_long *t_so_long)
{
	if (t_so_long->heart == 2)
	{
		display_heart2(t_so_long);
	}
	else if (t_so_long->heart == 1)
	{
		display_heart1(t_so_long);
	}
	else if (t_so_long->heart == 0)
	{
		display_heart0(t_so_long);
	}
	return (0);
}

void	display_heart2(t_so_long *t_so_long)
{
	mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
		t_so_long->img.imgredheart, ((t_so_long->map.map_x - 3) * 100), 0);
	mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
		t_so_long->img.imgredheart, ((t_so_long->map.map_x - 2) * 100), 0);
	mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
		t_so_long->img.imgredheart, ((t_so_long->map.map_x - 1) * 100), 0);
}

void	display_heart1(t_so_long *t_so_long)
{
	mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
		t_so_long->img.imgredheart, ((t_so_long->map.map_x - 3) * 100), 0);
	mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
		t_so_long->img.imgredheart, ((t_so_long->map.map_x - 2) * 100), 0);
	mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
		t_so_long->img.imgdeadheart, ((t_so_long->map.map_x - 1) * 100), 0);
}

void	display_heart0(t_so_long *t_so_long)
{
	mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
		t_so_long->img.imgredheart, ((t_so_long->map.map_x - 3) * 100), 0);
	mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
		t_so_long->img.imgdeadheart, ((t_so_long->map.map_x - 2) * 100), 0);
	mlx_put_image_to_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
		t_so_long->img.imgdeadheart, ((t_so_long->map.map_x - 1) * 100), 0);
}

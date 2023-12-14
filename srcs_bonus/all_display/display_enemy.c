/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:06:26 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/14 18:44:07 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	display_enemy(t_so_long *t_so_long)
{
	int	i;
	int	j;

	i = 0;
	while (i <= t_so_long->map.map_y)
	{
		j = 0;
		while (t_so_long->map.map[i][j] == '1'
		|| t_so_long->map.map[i][j] == '!' || t_so_long->map.map[i][j] == '0'
			|| t_so_long->map.map[i][j] == 'E'
				|| t_so_long->map.map[i][j] == 'P'
					|| t_so_long->map.map[i][j] == 'C')
		{
			if (t_so_long->map.map[i][j] == '!')
				mlx_put_image_to_window(t_so_long->mlx.mlx,
					t_so_long->mlx.mlx_win, t_so_long->img.imgenemy,
					(j * 100), (i * 100));
			j++;
		}
		i++;
	}
	return (0);
}

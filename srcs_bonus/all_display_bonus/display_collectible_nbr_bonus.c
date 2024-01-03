/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_collectible_nbr_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:30:31 by lbirloue          #+#    #+#             */
/*   Updated: 2024/01/03 15:55:24 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	display_collectible_nbr(t_so_long *t_so_long)
{
	char	*str;

	str = ft_itoa(t_so_long->element.colectible.colectible_count);
	mlx_string_put(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
		20, 70, 0x00000000, "take");
	if (t_so_long->element.colectible.colectible_count != 0)
		mlx_string_put(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
			65, 70, 0x00000000, str);
	else
		mlx_string_put(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
			65, 70, 0x00000000, "0");
	mlx_string_put(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
		100, 70, 0x00000000, "items to leave");
	free (str);
	str = NULL;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_collectible_nbr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:30:31 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/14 18:44:07 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	display_collectible_nbr(t_so_long *t_so_long)
{
	char	*str;

	str = ft_itoa(t_so_long->element.colectible.colectible_count);
	mlx_string_put(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
		30, 75, 0x00000000, "take");
	if (t_so_long->element.colectible.colectible_count != 0)
		mlx_string_put(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
			65, 75, 0x00000000, str);
	else
		mlx_string_put(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
			65, 75, 0x00000000, "0");
	mlx_string_put(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
		90, 75, 0x00000000, "items to leave");
	free (str);
	str = NULL;
	return ;
}

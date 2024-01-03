/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:27:30 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/14 13:56:14 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	display_move_nbr(t_so_long *t_so_long)
{
	char	*str;

	str = ft_itoa(t_so_long->move_nbr);
	mlx_string_put(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
		30, 60, 0x00000000, "move :");
	if (!str)
		mlx_string_put(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
			85, 60, 0x00000000, "0");
	else
		mlx_string_put(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win,
			85, 60, 0x00000000, str);
	free (str);
	str = NULL;
	return ;
}

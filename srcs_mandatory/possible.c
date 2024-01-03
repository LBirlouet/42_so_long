/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:15:21 by lbirloue          #+#    #+#             */
/*   Updated: 2024/01/03 07:56:55 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	possible_win(t_so_long *t_so_long)
{
	if ((t_so_long->element.player.player_x == t_so_long->element.exit.exit_x)
		&& (t_so_long->element.player.player_y 
			== t_so_long->element.exit.exit_y)
		&& (t_so_long->element.colectible.colectible_count == 0))
	{
		close_window(0, t_so_long);
	}
	return (0);
}

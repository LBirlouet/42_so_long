/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:58:05 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/14 15:34:32 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_verif_map(t_so_long *t_so_long)
{
	t_so_long->element.exit.exit_count = 0;
	t_so_long->element.colectible.colectible_count = 0;
	t_so_long->element.player.player_count = 0;
	t_so_long->element.enemy.enemy_count = 0;
	return ;
}

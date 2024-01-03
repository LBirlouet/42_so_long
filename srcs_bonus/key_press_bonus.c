/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:12:06 by lbirloue          #+#    #+#             */
/*   Updated: 2024/01/03 07:56:55 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_key_press(int keycode, t_so_long *t_so_long)
{
	int	verif;

	if (t_so_long->status == 0)
	{
		verif = move(keycode, t_so_long);
		verif = possible_win(t_so_long);
		verif = possible_loose(t_so_long);
	}
	verif = escape(keycode, t_so_long);
	return (0);
}

int	close_window(int keycode, t_so_long *t_so_long)
{
	(void) keycode;
	mlx_destroy_window(t_so_long->mlx.mlx, t_so_long->mlx.mlx_win);
	return (free_all_exit(t_so_long));
}

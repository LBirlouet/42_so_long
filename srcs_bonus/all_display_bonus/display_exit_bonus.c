/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:04:45 by lbirloue          #+#    #+#             */
/*   Updated: 2024/01/03 07:56:55 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	display_exit(t_so_long *t_so_long)
{
	mlx_put_image_to_window(t_so_long->mlx.mlx,
		t_so_long->mlx.mlx_win, t_so_long->img.imgexit,
		(t_so_long->element.exit.exit_x * 100),
		(t_so_long->element.exit.exit_y * 100));
	return (0);
}

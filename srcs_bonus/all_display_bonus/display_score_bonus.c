/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_score.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:16:46 by lbirloue          #+#    #+#             */
/*   Updated: 2024/01/03 07:56:55 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	display_score(t_so_long *t_so_long)
{
	mlx_put_image_to_window(t_so_long->mlx.mlx,
		t_so_long->mlx.mlx_win, t_so_long->img.imgdisplay_score,
		10, 10);
	return (0);
}

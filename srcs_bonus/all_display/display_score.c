/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_score.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:16:46 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/14 18:44:07 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	display_score(t_so_long *t_so_long)
{
	mlx_put_image_to_window(t_so_long->mlx.mlx,
		t_so_long->mlx.mlx_win, t_so_long->img.imgdisplay_score,
		10, 10);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:58:41 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/20 12:28:47 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	element_verif(t_so_long *t_so_long)
{
	if (t_so_long->element.exit.exit_count != 1)
		return (-1);
	return (0);
}

int	verif_exit(t_so_long *t_so_long)
{
	int	x_exit;
	int	y_exit;

	x_exit = t_so_long->element.exit.exit_x;
	y_exit = t_so_long->element.exit.exit_y;
	if (t_so_long->verif.map_verif[y_exit][x_exit - 1] == 'V'
		|| t_so_long->verif.map_verif[y_exit][x_exit + 1] == 'V'
			|| t_so_long->verif.map_verif[y_exit - 1][x_exit] == 'V'
				|| t_so_long->verif.map_verif[y_exit + 1][x_exit] == 'V')
		return (0);
	return (-1);
}

int	verif_map_possible(t_so_long *t_so_long)
{
	int	verif;

	t_so_long->verif.colectible_verif 
		= t_so_long->element.colectible.colectible_count;
	verif = copy_map(t_so_long);
	fillpaths(t_so_long, t_so_long->element.player.player_x,
		t_so_long->element.player.player_y);
	verif = verif_exit(t_so_long);
	if (verif == -1)
		return (return_free_map_verif(t_so_long, t_so_long->map.map_y, -1));
	if (t_so_long->verif.colectible_verif != 0)
		return (return_free_map_verif(t_so_long, t_so_long->map.map_y, -1));
	return (return_free_map_verif(t_so_long, t_so_long->map.map_y, 0));
}

void	fillpaths(t_so_long *t_so_long, int row, int col)
{
	if (row < 0 || col < 0
		|| col > t_so_long->map.map_y
		|| row > t_so_long->map.map_x 
		|| t_so_long->verif.map_verif[col][row] == '1' 
		|| t_so_long->verif.map_verif[col][row] == 'V')
		return ;
	if (t_so_long->verif.map_verif[col][row] == 'C')
		t_so_long->verif.colectible_verif--;
	t_so_long->verif.map_verif[col][row] = 'V';
	fillpaths(t_so_long, row - 1, col);
	fillpaths(t_so_long, row + 1, col);
	fillpaths(t_so_long, row, col - 1);
	fillpaths(t_so_long, row, col + 1);
}

int	verif_arg(int argc, char *argv)
{
	int	len;

	if (argc > 2)
	{
		ft_printf("Error\nPlease, enter only one map name\n");
		return (-1);
	}
	if (argc != 2 || !argv[1])
	{
		ft_printf("Error\nPlease, enter a map name\n");
		return (-1);
	}
	len = (ft_strlen(argv) - 1);
	if (len < 4 || argv[len - 3] != '.' || argv[len - 2] != 'b'
		|| argv[len - 1] != 'e' || argv[len] != 'r')
	{
		ft_printf("Error\nInvalid map name\n");
		return (-1);
	}
	return (0);
}

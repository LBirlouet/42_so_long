/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:57:34 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/21 09:54:20 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_so_long	t_so_long;
	int			verif;

	if (verif_arg(argc, argv[1]) == -1)
		return (0);
	t_so_long.heart = 2;
	t_so_long.element.player.rotation = 8;
	t_so_long.map.map_name = argv[1];
	t_so_long.map.map_fd = open(t_so_long.map.map_name, O_RDONLY, 0644);
	if (t_so_long.map.map_fd == -1)
		return (-1);
	verif = verif_map(&t_so_long, 0, 0, 0);
	if (verif == -1)
		return (error_msg());
	if (malloc_map(&t_so_long) == -1)
		return (malloc_map_error_msg());
	if (verif_map_possible(&t_so_long) == -1)
		return (error_msg());
	verif = display(&t_so_long);
	if (verif == -1)
		return (-1);
	return (0);
}

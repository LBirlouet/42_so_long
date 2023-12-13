/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:57:34 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/13 17:13:53 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



int main(int argc, char **argv)
{
	t_so_long t_so_long;
	int		verif;

	(void) argc;
	(void) argv;	
	// if (argc != 0 !! !argv[1])
	// 	return (0);
	t_so_long.heart = 2;
	t_so_long.element.player.rotation = 8;
	t_so_long.map.map_name = argv[1];
	t_so_long.map.map_fd = open(t_so_long.map.map_name, O_RDONLY, 0644);
	if (t_so_long.map.map_fd == -1)
		return (-1);
	verif = verif_map(&t_so_long);
	if (verif == -1)
		return (error_msg());
	verif = malloc_map(&t_so_long);
	verif = verif_map_possible(&t_so_long);
	if (verif == -1)
		return (-1);
	verif = display(&t_so_long);
	if (verif == -1)
		return (-1);
	return (0);
}
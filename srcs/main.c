/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:57:34 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/12 18:14:54 by lbirloue         ###   ########.fr       */
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
	t_so_long.map.map_name = "./maps/map_full_coll.txt";
	t_so_long.map.map_fd = open(t_so_long.map.map_name, O_RDONLY, 0644);
	if (t_so_long.map.map_fd == -1)
		return (-1);
	verif = verif_map(&t_so_long);
	if (verif == -1)
		return (0);
	verif = malloc_map(&t_so_long);
//	printf("%s\n%s\n%s\n", t_so_long.map.map[0],t_so_long.map.map[1], t_so_long.map.map[2]);
	if (verif == -1)
		return (-1);
	verif = display(&t_so_long);
	if (verif == -1)
		return (-1);
	return (0);
}
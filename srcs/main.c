/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:57:34 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/11 10:25:34 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



int main()
{
	t_so_long t_so_long;
	int		verif;

	t_so_long.map.map_name = "./maps/map1.txt";
	t_so_long.map.map_fd = open(t_so_long.map.map_name, O_RDONLY, 0644);
	if (t_so_long.map.map_fd == -1)
		return (-1);
	verif = verif_map(&t_so_long);
	if (verif == -1)
		return (-1);
	verif = display(&t_so_long);
	if (verif == -1)
		return (-1);
	return (0);
}
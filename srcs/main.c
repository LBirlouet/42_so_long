/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:57:34 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/05 19:12:12 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



int main()
{
	t_map	t_map;
	t_map_element t_map_element;
	int		verif;

	t_map.map_name = "./maps/map1.txt";
	t_map.map_fd = open(t_map.map_name, O_RDONLY, 0644);
	if (t_map.map_fd == -1)
		return (-1);
	verif = verif_map(&t_map, &t_map_element);
	if (verif == -1)
		return (-1);
	verif = display(&t_map, &t_map_element);
	if (verif == -1)
		return (-1);
	return (0);
}
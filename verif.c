/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:58:41 by lbirloue          #+#    #+#             */
/*   Updated: 2023/11/28 14:18:10 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int verif_map(char *map)
{
	if (verif_map_rectangle() == -1)
		return (-1)
}

int	verif_map_rectangle(char *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i] != 0 || map[i] != '\n')
		i++;
	while (map[j] != 0)
	{
		while (map[j] != '\n')
			j++;
		if (j != i)
			return (-1)
		i = j;
	}
	return (0)
}

int verif_border(char *map)
{
	int i;

	i = 0;
	while (map[i] != '\n')
	{
		if (map[i] != '1')
			return (-1);
		i++;
	}
	while (map[i] != 0)
	{
		if (map[i - 1] == '\n' && map[i] != '1')
			return (-1);
		if ((map [i + 1] == '\n' || map [i + 1] == '\0') && map[i] != 1)
			return (-1);
		i++;
	}
	return (0);
}
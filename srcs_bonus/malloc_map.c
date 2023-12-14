/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 08:04:30 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/14 18:44:07 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	malloc_map(t_so_long *t_so_long)
{
	int	i;
	int	verif;

	i = 0;
	t_so_long->map.map = malloc(sizeof(char *) * (t_so_long->map.map_y + 1));
	if (!t_so_long->map.map)
		return (-1);
	while (i <= t_so_long->map.map_y)
	{
		t_so_long->map.map[i] = malloc(sizeof(char)
				* (t_so_long->map.map_x + 2));
		if (!t_so_long->map.map[i])
			return (return_free_map_verif(t_so_long, i, -1));
		i++;
	}
	verif = fill_map(t_so_long);
	return (verif);
}

int	fill_map(t_so_long *t_so_long)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	t_so_long->map.map_fd = open(t_so_long->map.map_name, O_RDONLY, 0644);
	if (t_so_long->map.map_fd == -1)
		return (-1);
	while (i <= t_so_long->map.map_y)
	{
		j = 0;
		line = get_next_line(t_so_long->map.map_fd);
		while (j <= t_so_long->map.map_x)
		{
			t_so_long->map.map[i][j] = line[j];
			j++;
		}
		t_so_long->map.map[i][j] = '\0';
		free(line);
		i++;
	}
	return (0);
}

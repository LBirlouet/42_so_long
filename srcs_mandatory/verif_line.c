/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:30:21 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/20 12:38:03 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	verif_line(char *map, int line_size, t_so_long *t_so_long, int line_counter)
{
	int	i;

	i = 0;
	if (!map || map[0] != '1' || map[line_size] != '1')
		return (-1);
	while (i < line_size)
	{
		if (map[i] == 'C')
			t_so_long->element.colectible.colectible_count += 1;
		if (map[i] == 'E')
			exit_count_pos(t_so_long, i, line_counter);
		if (map[i] == 'P')
			player_count_pos(t_so_long, i, line_counter);
		if (map[i] != '1' && map[i] != '0' && map[i] != 'P' 
			&& map[i] != 'C' && map[i] != 'E')
			return (-1);
		i++;
	}
	return (0);
}

int	verif_first_line(char *map)
{
	int	i;

	i = 0;
	if (!map)
		return (-1);
	while (map[i] != '\n')
	{
		if (map[i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	verif_last_line(int line_counter, t_so_long *t_so_long, int verif, int i)
{
	char	*line;

	(void) verif;
	t_so_long->map.map_fd = open(t_so_long->map.map_name, O_RDONLY, 0644);
	if (t_so_long->map.map_fd == -1)
		return (-1);
	while (line_counter > 0)
	{
		line = get_next_line(t_so_long->map.map_fd);
		free(line);
		line_counter--;
	}
	line = get_next_line(t_so_long->map.map_fd);
	if (ft_strlen_before_newline(line) != t_so_long->map.map_x 
		|| t_so_long->map.map_x == t_so_long->map.map_y)
		return (-1);
	while (i != t_so_long->map.map_x)
	{
		if (line [i] != '1')
			return (-1);
		i++;
	}
	free(line);
	close(t_so_long->map.map_fd);
	return (0);
}

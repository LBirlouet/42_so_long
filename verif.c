/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:58:41 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/05 10:28:03 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int verif_map(int fd, t_map *t_map, char *map_name)
{
	char			*line;
	int				line_size;
	int				verif;
	int				line_counter;
	t_colectible	t_colectible;
	t_exit			t_exit;
	
	line_counter = 0;
	line = get_next_line(fd);
	verif = verif_first_line(line);
	if (verif == -1)
	{
		free(line);
		return (-1);
	}
	line_size = ft_strlen_before_newline(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		line_counter++;
		verif = verif_line(line, (line_size - 1), &t_colectible, &t_exit);
		if (verif == -1 || (ft_strlen_before_newline(line) != line_size))
		{
			free(line);
			return (-1);
		}
	}
	close(fd);
	t_map->map_x = line_size;
	t_map->map_y = line_counter;
	verif = verif_last_line(line_counter, map_name, t_map);
	if (verif == -1)
		return (-1);
	return (0);
	// if (verif_map_rectangle() == -1)
	// 	return (-1);
}

int	verif_line(char *map, int line_size, t_colectible *t_colectible, t_exit *t_exit)
{

	int 	i;
	i = 0;
	if (map[0] != '1' || map[line_size] != '1')
	{
		printf("jhgf%d\n", line_size);
		return (-1);
	}
	while (i < line_size)
	{
		if (map[i] == 'C')
			t_colectible->colectible_count += 1;
		if (map[i] == 'E')
			t_exit->exit_count += 1;
		i++;
	}
	if (t_exit->exit_count > 1)
		return (-1);
	return (0);
}

int verif_first_line(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
	{
		if (map[i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	verif_last_line(int line_counter, char *map_name, t_map *t_map)
{
	char	*line;
	int		verif;
	int		i;
	
	i = 0;
	verif = 0;
	int fd = open(map_name, O_RDONLY, 0644);
	if (fd == -1)
		return (1);
	while (line_counter > 0)
	{
		line = get_next_line(fd);
		free(line);
		line_counter--;
	}
	line = get_next_line(fd);
	if (ft_strlen_before_newline(line) != t_map->map_x || t_map->map_x == t_map->map_y)
		return (-1);
	while (i != t_map->map_x)
	{
		if (line [i] != '1')
			return (-1);
		i++;
	}
	close(fd);
	return (0);
}


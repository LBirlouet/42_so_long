/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:24:56 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/21 09:54:57 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	verif_map(t_so_long *t_so_long, int line_counter, int line_size, int verif)
{
	char	*line;

	init_verif_map(t_so_long);
	line = get_next_line(t_so_long->map.map_fd);
	verif = verif_first_line(line);
	if (verif == -1)
		return (ret_free_line(line));
	line_size = ft_strlen_before_newline(line);
	if (line_size > 25)
		return (-1);
	while (line)
	{
		free(line);
		line = get_next_line(t_so_long->map.map_fd);
		if (!line)
			break ;
		line_counter++;
		verif = verif_line(line, (line_size - 1), t_so_long, line_counter);
		if (verif == -1 || (ft_strlen_before_newline(line) != line_size))
		{
			free(line);
			return (-1);
		}
	}
	return (verif_map2(t_so_long, line_size, line_counter));
}

int	verif_map2(t_so_long *t_so_long, int line_size, int line_counter)
{
	int	verif;

	verif = 0;
	close(t_so_long->map.map_fd);
	if (line_counter > 12)
		return (-1);
	t_so_long->map.map_x = line_size;
	t_so_long->map.map_y = line_counter;
	verif = element_verif(t_so_long);
	if (verif == -1 || t_so_long->element.colectible.colectible_count < 1)
		return (-1);
	verif = verif_last_line(line_counter, t_so_long, 0, 0);
	if (verif == -1)
		return (-1);
	return (0);
}

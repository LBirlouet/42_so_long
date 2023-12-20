/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:08:15 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/20 11:12:00 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_strlen_before_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0 && str[i] != '\n')
		i++;
	return (i);
}

int	copy_map(t_so_long *t_so_long)
{
	int	i;
	int	verif;

	i = 0;
	t_so_long->verif.map_verif = malloc(sizeof(char *)
			* (t_so_long->map.map_y + 1));
	if (!t_so_long->verif.map_verif)
		return (-1);
	while (i <= t_so_long->map.map_y)
	{
		t_so_long->verif.map_verif[i] = malloc(sizeof(char)
				* (t_so_long->map.map_x + 2));
		if (!t_so_long->verif.map_verif[i])
			return (-1);
		i++;
	}
	verif = fill_map_verif(t_so_long);
	return (0);
}

int	fill_map_verif(t_so_long *t_so_long)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= t_so_long->map.map_y)
	{
		j = 0;
		while (j <= t_so_long->map.map_x)
		{
			t_so_long->verif.map_verif[i][j] = t_so_long->map.map[i][j];
			j++;
		}
		t_so_long->verif.map_verif[i][j] = '\0';
		i++;
	}
	return (0);
}

int	ret_free_line(char *line)
{
	free(line);
	return (-1);
}

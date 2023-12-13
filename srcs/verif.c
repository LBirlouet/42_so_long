/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:58:41 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/13 13:21:03 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int verif_map(t_so_long *t_so_long)
{
	char			*line;
	int				line_size;
	int				verif;
	int				line_counter;
	
	t_so_long->element.exit.exit_count = 0;
	t_so_long->element.colectible.colectible_count = 0;
	t_so_long->element.player.player_count = 0;
	t_so_long->element.enemy.enemy_count = 0;
	line_counter = 0;
	line = get_next_line(t_so_long->map.map_fd);
	verif = verif_first_line(line);
	if (verif == -1)
	{
		free(line);
		return (-1);
	}
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
	close(t_so_long->map.map_fd);
	if (line_counter > 12)
		return (-1);
	t_so_long->map.map_x = line_size;
	t_so_long->map.map_y = line_counter;
	verif = element_verif(t_so_long);
	if (verif == -1 || t_so_long->element.colectible.colectible_count < 1)
		return (-1);
//	printf("yaaaa\n");
	verif = verif_last_line(line_counter, t_so_long);
	if (verif == -1)
		return (-1);
	return (0);
}

int	element_verif(t_so_long *t_so_long)
{
	if (t_so_long->element.exit.exit_count != 1)
		return (-1);
	return (0);
}

int	verif_line(char *map, int line_size, t_so_long *t_so_long, int line_counter)
{
	int	i;

	i = 0;
	if (map[0] != '1' || map[line_size] != '1')
		return (-1);
	while (i < line_size)
	{
		if (map[i] == 'C')
			t_so_long->element.colectible.colectible_count += 1;
		if (map[i] == 'E')
		{
			t_so_long->element.exit.exit_count++;
			t_so_long->element.exit.exit_x = i;
			t_so_long->element.exit.exit_y = line_counter;
		}
		if (map[i] == 'P')
		{
			t_so_long->element.player.player_count++;
			t_so_long->element.player.player_x = i;
			t_so_long->element.player.player_y = line_counter;
		}
		if (map[i] == '!')
		{
			t_so_long->element.enemy.enemy_count++;
		}
		if (map[i] != '1' && map[i] != '0' && map[i] != 'P' && map[i] != 'C' && map[i] != 'E' && map[i] != '!')
			return (-1);
		i++;
	}
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

int	verif_last_line(int line_counter, t_so_long *t_so_long)
{
	char	*line;
	int		verif;
	int		i;
	
	i = 0;
	verif = 0;
	t_so_long->map.map_fd = open(t_so_long->map.map_name, O_RDONLY, 0644);
	if (t_so_long->map.map_fd == -1)
		return (1);
	while (line_counter > 0)
	{
		line = get_next_line(t_so_long->map.map_fd);
		free(line);
		line_counter--;
	}
	line = get_next_line(t_so_long->map.map_fd);
	if (ft_strlen_before_newline(line) != t_so_long->map.map_x || t_so_long->map.map_x == t_so_long->map.map_y)
		return (-1);
	while (i != t_so_long->map.map_x)
	{
		if (line [i] != '1')
			return (-1);
		i++;
	}
	close(t_so_long->map.map_fd);
	return (0);
}

int	verif_exit(t_so_long *t_so_long)
{
	int x_exit;
	int y_exit;

	x_exit = t_so_long->element.exit.exit_x;
	y_exit = t_so_long->element.exit.exit_y;
	if (t_so_long->verif.map_verif[y_exit][x_exit - 1] == 'V' || t_so_long->verif.map_verif[y_exit][x_exit + 1] == 'V' || t_so_long->verif.map_verif[y_exit - 1][x_exit] == 'V' || t_so_long->verif.map_verif[y_exit + 1][x_exit] == 'V')
		return (0);
	return (-1);
}


int		verif_map_possible(t_so_long *t_so_long)
{
	int verif;

	t_so_long->verif.colectible_verif = t_so_long->element.colectible.colectible_count;
	verif = copy_map(t_so_long);
	fillPaths(t_so_long, t_so_long->element.player.player_x, t_so_long->element.player.player_y);
	verif = verif_exit(t_so_long);
	if (verif == -1)
		return (-1);
	printf("%d\n", t_so_long->verif.colectible_verif);
	if (t_so_long->verif.colectible_verif != 0)
		return (return_free_map_verif(t_so_long, t_so_long->map.map_y, -1));
	return (0);
}

void fillPaths(t_so_long *t_so_long, int row, int col)
{
	// printf("row =%d | col = %d \n%d\n", row, col, t_so_long->map.map_y);
	// printf("%c\n", t_so_long->verif.map_verif[row][col]);
	printf("x = %d | y = %d\n", row, col);
	printf("%s\n", t_so_long->verif.map_verif[1]);
	printf("t_so_long->verif.map_verif[%d][%d] = %c\n", col, row, t_so_long->verif.map_verif[col][row]);
    if (row < 0 || col < 0 || col > t_so_long->map.map_y || row > t_so_long->map.map_x || t_so_long->verif.map_verif[col][row] == '1' || t_so_long->verif.map_verif[col][row] == 'V' || t_so_long->verif.map_verif[col][row] == '!')
	{
		printf("pasbon\n");
        return;
    }
	printf("hu\n");
	if (t_so_long->verif.map_verif[col][row] == 'C')
	{
		printf("%d\n", t_so_long->verif.colectible_verif);
		t_so_long->verif.colectible_verif--;
	}
	t_so_long->verif.map_verif[col][row] = 'V';
	fillPaths(t_so_long, row - 1, col);
	fillPaths(t_so_long, row + 1, col);
	fillPaths(t_so_long, row, col - 1);
	fillPaths(t_so_long, row, col + 1);
}


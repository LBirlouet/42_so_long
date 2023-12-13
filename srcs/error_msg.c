/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:05:04 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/13 17:21:24 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_msg(void)
{
	ft_printf("Error\n");
	ft_printf("Invalid map");
	return (-1);
}

int	return_free_map_verif(t_so_long *t_so_long, int tab_nbr, int ret)
{
	//tab_nbr += 1;
	while (tab_nbr >= 0)
	{
		free(t_so_long->verif.map_verif[tab_nbr]);
		t_so_long->verif.map_verif[tab_nbr] = NULL;
		tab_nbr--;
	}
	free(t_so_long->verif.map_verif);
	t_so_long->verif.map_verif = NULL;
	return (ret);
}

int free_all_exit(t_so_long *t_so_long)
{
	int i;

	i = t_so_long->map.map_y;
//	printf("%d\n", i);
	while (i >= 0)
	{
		free(t_so_long->map.map[i]);
		t_so_long->map.map[i] = NULL;
		i--;
	}
	free(t_so_long->map.map);
	t_so_long->map.map = NULL;
	system("leaks so_long");
//	system("leaks so_long");
	exit (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:38:10 by lbirloue          #+#    #+#             */
/*   Updated: 2024/01/03 07:56:55 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	c_nbr(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*posint(int char_nbr, int n, char *ret)
{
	int		char_0;
	char	char_c;

	char_0 = char_nbr;
	while (char_nbr > 0)
	{
		char_c = ((n % 10) + 48);
		n = n / 10;
		ret[char_nbr - 1] = char_c;
		char_nbr--;
	}
	ret[char_0] = 0;
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		char_nbr;
	int		char_0;

	char_nbr = c_nbr(n);
	char_0 = char_nbr;
	if (n >= 0)
		char_0 = char_0 + 1;
	if (n == 0)
		return (0);
	else
	{
		ret = malloc((char_0) * sizeof(char));
		if (!ret)
			return (0);
		if (n > 0)
			return (posint(char_nbr, n, ret));
	}
	return (0);
}

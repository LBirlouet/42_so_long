/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:50:13 by lbirloue          #+#    #+#             */
/*   Updated: 2023/10/30 18:23:18 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_adress(unsigned long n)
{
	char const	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putnbr_adress(n / 16);
		ft_putnbr_adress(n % 16);
	}
	else
		ft_putchar(base[n]);
}

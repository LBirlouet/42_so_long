/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbirloue <lbirloue@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:17:02 by lbirloue          #+#    #+#             */
/*   Updated: 2023/12/12 17:44:08 by lbirloue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_printf2(const char *str, va_list lst);
int		repartflag(const char c, va_list lst);
int		ft_verif_flag(const char c);
void	ft_putnbr(int n);
int		nbr_hexa(unsigned int n, int i);
void	ft_putnbr_hexalower(unsigned int n);
void	ft_putnbr_hexatoupper(unsigned int n);
void	ft_putnbr_unsigned(unsigned int n);
void	ft_putnbr_adress(unsigned long n);
int		nbr_count(int n);
int		nbr_count_unsigned(unsigned int n);
int		nbr_count_p(void const *p);
int		ft_putstr(char *str);
int		ft_putchar(char c);
size_t	ft_strlen_printf(const char *str);

#endif
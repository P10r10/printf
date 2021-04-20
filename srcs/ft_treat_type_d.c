/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_type_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:28:25 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/18 16:30:52 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>//REMOVE

size_t	ft_treat_type_d(t_flags *flag, va_list ap, char *buf, size_t count)
{
	char *s;
	int len;
	int pad = 0;

 	s = ft_putnbr(va_arg(ap, int), buf, 0);
	if (*s == '0' && flag->precision == 0)
		return (0);
	len = ft_strlen(s);
	if (flag->precision > len)
	{
		flag->width = flag->precision;
		flag->zero = 1;
		flag->minus = 0;
	}
	if (flag->width > len)
		pad = flag->width - len;
//	printf("HERE: %d\n", flag->minus);
//	getchar();
	if (flag->minus)
		count += ft_putstr(s);
	
	if (flag->zero)
		count += ft_fill(pad, '0');
	else
		count += ft_fill(pad, ' ');
	
	if (!(flag->minus))
		count += ft_putstr(s);

	return (count);
}
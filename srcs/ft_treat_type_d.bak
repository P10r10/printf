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

size_t	ft_treat_type_d(t_flags *flag, va_list ap, char *buf, size_t count)
{
	int len;
	char *s;

	if (flag->placehold_w)
		flag->width = va_arg(ap, int);
	if (flag->placehold_p)
		flag->precision = va_arg(ap, int);
	if (flag->width < 0)
	{
		flag->minus = 1;
		flag->width *= -1;
	}

 	s = ft_putnbr(va_arg(ap, int), buf, 0);
	len = ft_strlen(s);

	if (flag->minus)
	{
		if (flag->precision > len)
			count += ft_fill(flag->precision - len, '0');
		count += ft_putstr(s);
	}

	if (flag->width > len)
		count += ft_fill(flag->width - len, ' ');

	if (!(flag->minus))
	{
		if (flag->precision > len)
			count += ft_fill(flag->precision - len, '0');
		count += ft_putstr(s);
	}

	return (count);
}

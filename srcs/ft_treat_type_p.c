/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_type_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:34:28 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/18 16:35:42 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putchar_minus(char *ptr)
{
	ft_putstr("0x");
	ft_putstr(ptr);
}

size_t	ft_treat_type_p(t_flags *flag, va_list ap, char *buf, size_t count)
{
	int		len;

	if (flag->placehold_w)
		flag->width = va_arg(ap, int);
	if (flag->placehold_p)
		flag->precision = va_arg(ap, int);
	if (flag->width < 0)
	{
		flag->minus = 1;
		flag->width *= -1;
	}
	ft_putnbr_h(va_arg(ap, long), buf, 'x');
	len = ft_strlen(buf) + 2;
	count += len;
	if (flag->minus)
		ft_putchar_minus(buf);
	if (flag->width > len)
		count += ft_fill(flag->width - len, ' ');
	if (!(flag->minus))
		ft_putchar_minus(buf);
	return (count);
}

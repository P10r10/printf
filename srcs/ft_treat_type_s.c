/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_type_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:32:32 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/18 16:34:07 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_putchar_prec(char *s, t_flags *flag)
{
	size_t	count;

	count = 0;
	while (*s && flag->precision--)
	{
		ft_putchar(*s++);
		count++;
	}
	return (count);
}

static char	*ft_check_null(char *s, t_flags *flag)
{
	if (!s)
	{
		if (flag->precision == 0 )
			s = "";
		else
			s = "(null)";
	}
	return (s);
}

size_t	ft_treat_type_s(t_flags *flag, va_list ap, size_t count)
{
	int		len;
	char	*s;

	if (flag->placehold_w)
		flag->width = va_arg(ap, int);
	if (flag->placehold_p)
		flag->precision = va_arg(ap, int);
	if (flag->width < 0)
	{
		flag->minus = 1;
		flag->width *= -1;
	}
	s = va_arg(ap, char *);
	s = ft_check_null(s, flag);
	len = ft_strlen(s);
	if (flag->precision >= 0 && flag->precision < len)
		len = flag->precision;
	if (flag->minus)
		count += ft_putchar_prec(s, flag);
	if (flag->width > len)
		count += ft_fill(flag->width - len, ' ');
	if (!(flag->minus))
		count += ft_putchar_prec(s, flag);
	return (count);
}

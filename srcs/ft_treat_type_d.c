/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_type_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:28:25 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/27 18:03:38 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_pad(t_flags *flag, int n_digits, int is_neg)
{
	size_t	count;

	count = 0;
	if (flag->precision > n_digits)
		n_digits = flag->precision;
	if (flag->width > (n_digits + is_neg))
		count = ft_fill(flag->width - n_digits - is_neg, ' ');
	return (count);
}

static size_t	ft_zero_prec(t_flags *flag, int n_digits)
{
	size_t	count;

	count = ft_fill(flag->precision - n_digits, '0');
	return (count);
}

static size_t	ft_zero_flag(t_flags *flag, int n_digits, int is_neg)
{
	size_t	count;

	count = 0;
	if (flag->width > (n_digits + is_neg))
		count = ft_fill(flag->width - n_digits - is_neg, '0');
	return (count);
}

static void	ft_check_flag(t_flags *flag, va_list ap)
{
	if (flag->placehold_w)
		flag->width = va_arg(ap, int);
	if (flag->placehold_p)
		flag->precision = va_arg(ap, int);
	if (flag->width < 0)
	{
		flag->minus = 1;
		flag->width *= -1;
	}
	if (flag->precision < -1)
		flag->precision = -1;
	if (flag->precision != -1 || flag->minus)
		flag->zero = 0;
}

size_t	ft_treat_type_d(t_flags *flag, va_list ap, char *buf, size_t count)
{
	int	is_neg;

	is_neg = 0;
	ft_check_flag(flag, ap);
	ft_putnbr(va_arg(ap, int), buf, 0, 0);
	if (*buf == '0' && flag->precision == 0)
		return (ft_pad(flag, ft_strlen(buf) - 1, is_neg));
	if (*buf == '-')
	{
		is_neg = 1;
		buf++;
	}
	if (!flag->minus && !flag->zero)
		count += ft_pad(flag, ft_strlen(buf), is_neg);
	if (is_neg)
		count += ft_putchar('-');
	if (flag->precision > (int)ft_strlen(buf))
		count += ft_zero_prec(flag, ft_strlen(buf));
	if (flag->zero)
		count += ft_zero_flag(flag, ft_strlen(buf), is_neg);
	count += ft_putstr(buf);
	if (flag->minus)
		count += ft_pad(flag, ft_strlen(buf), is_neg);
	return (count);
}

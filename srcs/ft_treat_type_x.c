/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_type_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:46:54 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/25 17:26:07 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_pad(t_flags *flag, int n_digits)
{
	size_t	count;

	count = 0;
	if (flag->precision > n_digits)
		n_digits = flag->precision;
	if (flag->width > n_digits)
		count = ft_fill(flag->width - n_digits, ' ');
	return (count);
}

static size_t	ft_zero_prec(t_flags *flag, int n_digits)
{
	size_t	count;

	count = ft_fill(flag->precision - n_digits, '0');
	return (count);
}

static size_t	ft_zero_flag(t_flags *flag, int n_digits)
{
	size_t	count;

	count = 0;
	if (flag->width > n_digits)
		count = ft_fill(flag->width - n_digits, '0');
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
	if (flag->precision != -1 || flag->minus)
		flag->zero = 0;
}

size_t	ft_treat_type_x(t_flags *flag, va_list ap, char *buf, char ch)
{
	int	count;

	count = 0;
	ft_check_flag(flag, ap);
	ft_putnbr_h(va_arg(ap, int), buf, ch, 0);
	if (*buf == '0' && flag->precision == 0)
		return (ft_pad(flag, ft_strlen(buf) - 1));
	if (!flag->minus && !flag->zero)
		count += ft_pad(flag, ft_strlen(buf));
	if (flag->precision > (int)ft_strlen(buf))
		count += ft_zero_prec(flag, ft_strlen(buf));
	if (flag->zero)
		count += ft_zero_flag(flag, ft_strlen(buf));
	count += ft_putstr(buf);
	if (flag->minus)
		count += ft_pad(flag, ft_strlen(buf));
	return (count);
}

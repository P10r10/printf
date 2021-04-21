/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_type_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:28:25 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/20 21:19:24 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>//REMOVE

size_t	ft_treat_type_d(t_flags *flag, va_list ap, char *buf, size_t count)
{
 	ft_putnbr(va_arg(ap, int), buf, 0);
	if (*buf == '0' && flag->precision == 0)//caso especial 0
		return (0);
//	if (flag->minus || flag->precision != -1)
//		flag->zero = 0;
	if (*buf == '-' && flag->precision != -1)//caso -00003
		ft_putchar(*buf++);
	if (*buf == '-' && flag->zero)
		ft_putchar(*buf++);
	if (flag->width > (int)ft_strlen(buf) && !(flag->minus))//right pad
	{
		if (flag->precision == -1)
		{
			if (!flag->zero)
				ft_fill(flag->width - ft_strlen(buf), ' ');
		}
		else
		{
			if (flag->width > flag->precision)
				count += ft_fill(flag->width - flag->precision, ' ');//HERE
			count += ft_fill(flag->precision - ft_strlen(buf), '0');
		}
	}
	if (flag->precision > (int)ft_strlen(buf) && flag->width > flag->precision)
		count += ft_fill(flag->precision - ft_strlen(buf), '0');

//	printf("\nlen: |%d|\n", len);
//	printf("lnb: |%ld|\n", ft_strlen(buf));
	if (flag->zero)
		ft_fill(flag->width - ft_strlen(buf), '0');//HERE

	count += ft_putstr(buf);//CORE

	if (flag->width > (int)ft_strlen(buf) && flag->minus)//left pad
	{
		if (flag->precision == -1)
			count += ft_fill(flag->width - ft_strlen(buf), ' ');
		else
			count += ft_fill(flag->width - flag->precision, ' ');//rever ?
	}
	return (count);
}

//	printf("\nHERE: |%d|\n", pad_space);
//	getchar();

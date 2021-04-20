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
	char *s;
	int len;

 	s = ft_putnbr(va_arg(ap, int), buf, 0);
	len = ft_strlen(s);
	if (flag->width > len && !(flag->minus))
		count += ft_fill(flag->width - len, ' ');
	//HERE
	if (flag->precision > len)
	{
		if (*s != '-')// num > 0
			count += ft_fill(flag->precision - len, '0');
		else
		{
			s++;
			ft_putchar('-');
			len--;
			count += ft_fill(flag->precision - len, '0');
		}
	}
//	printf("\nHERE: %s\n", s);
//	getchar();
	count += ft_putstr(s);//CORE
	
	if (flag->width > len && flag->minus)
		count += ft_fill(flag->width - len, ' ');
	/*
	if (*s == '0' && flag->precision == 0)
		return (0);
	
	len = ft_strlen(s);
	
	if (flag->precision > len)
		flag->width = flag->precision;
		
	if (flag->width > flag->precision)
		pad = flag->width - flag->precision;
	***************
	if (flag->minus)
		count += ft_putstr(s);
	count += ft_fill(pad, ' ');
	
	//if (flag->zero)
		count += ft_fill(flag->precision - len, '0');
	****************
	if (!(flag->minus))
		count += ft_putstr(s);
*/
	return (count);
}

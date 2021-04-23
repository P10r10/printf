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

static size_t	ft_pad(t_flags *flag, int n_digits, int is_neg)
{
	size_t count;
	
	if (flag->width < (n_digits + is_neg))
		return (0);
	if (flag->width)// - n_digits - (size_t)is_neg)) > 0)//precision?
		count = ft_fill(flag->width - n_digits - (size_t)is_neg, ' ');
	return (count);
}

static size_t	ft_zero_prec(t_flags *flag, int n_digits)
{
	size_t count;
	
	count = ft_fill(flag->precision - n_digits, '0');
	return (count);
}

static size_t	ft_zero_flag(t_flags *flag, int n_digits, size_t is_neg)
{
	size_t count;
	
	count = ft_fill(flag->width - n_digits - is_neg, '0');
	return (count);
}

size_t	ft_treat_type_d(t_flags *flag, va_list ap, char *buf, size_t count)
{
	int is_neg;
	
	is_neg = 0;
	ft_putnbr(va_arg(ap, int), buf, 0);
	if (*buf == '-')
	{
		is_neg = 1;
		buf++;
	}
	
	if (!flag->minus && !flag->zero) //tem de haver outros testes?/PAD LEFT
		count += ft_pad(flag, ft_strlen(buf), is_neg);
		
	if (is_neg)//caso negativo
	{
		ft_putchar('-');//alterar putchar para devolver 1?;
		count++;//remover depois de alterar putchar
	}
	
	//00000 aqui! HERE
	if (flag->precision > (int)ft_strlen(buf))
		count += ft_zero_prec(flag, ft_strlen(buf));
	if (flag->zero)
		count += ft_zero_flag(flag, ft_strlen(buf), is_neg);
	count += ft_putstr(buf);//core
	if (flag->minus) //tem de haver outros testes?/PAD LEFT
		count = ft_pad(flag, ft_strlen(buf), is_neg);
	
	return (count);
}
//	printf("\nHERE: |%d|\n", pad_space);
//	getchar();
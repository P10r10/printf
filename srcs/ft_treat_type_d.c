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
	char *s;
	(void)flag;

 	s = ft_putnbr(va_arg(ap, int), buf, 0);
	
	count += ft_fill(flag->width - ft_strlen(s), ' ');
	count += ft_putstr(s);

	return (count);
}

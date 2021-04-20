/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_type_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:36:18 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/18 16:36:41 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_treat_type_c(t_flags *flag, va_list ap)
{
	size_t	count;

	count = 0;
	if (flag->placehold_w)
		flag->width = va_arg(ap, int);
	if (flag->width < 0)
	{
		flag->minus = 1;
		flag->width *= -1;
	}
	if (flag->minus)
		ft_putchar(va_arg(ap, int));
	if (flag->width > 1)
		count += ft_fill(flag->width - 1, ' ');
	if (!(flag->minus))
		ft_putchar(va_arg(ap, int));
	count++;
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_type_perc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:27:45 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/20 20:36:28 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_treat_type_perc(t_flags *flag)
{
	size_t	count;

	count = 0;
	if (flag->minus)
		flag->zero = 0;
	if (flag->width > 1 && !(flag->minus))
	{
		if (flag->zero)
			count += ft_fill(flag->width - 1, '0');
		else
			count += ft_fill(flag->width - 1, ' ');
	}
	ft_putchar('%');
	count ++;
	if (flag->width > 1 && flag->minus)
		count += ft_fill(flag->width - 1, ' ');
	return (count);
}

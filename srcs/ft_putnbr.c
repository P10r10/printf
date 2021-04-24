/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:04:14 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/13 18:08:51 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_putnbr(int n, char *res, int is_neg, int mod)
{
	char	*p;

	p = res;
	if (n == 0)
	{
		*p++ = '0';
		*p = '\0';
		return (res);
	}
	while (n)
	{
		mod = n % 10;
		if (mod < 0)
		{
			mod = -mod;
			is_neg = 1;
		}
		*p++ = mod + '0';
		n /= 10;
	}
	if (is_neg)
		*p++ = '-';
	*p = '\0';
	ft_str_reverse(res);
	return (res);
}

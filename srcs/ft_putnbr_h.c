/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:08:10 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/15 18:10:13 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	to_upper_h(char c)
{
	if (c >= 'a' && c <= 'f')
		return (c + ('A' - 'a'));
	return (c);
}

void	ft_putnbr_h(unsigned long n, char *res, char c)
{
	char	*hex;
	char	*p;

	hex = ft_strdup("0123456789abcdef");
	p = res;
	if (n == 0)
	{
		*p++ = '0';
		*p = '\0';
	}
	while (n)
	{
		if (c == 'x')
			*p++ = hex[n & 0xf];
		else if (c == 'X')
			*p++ = to_upper_h(hex[n & 0xf]);
		n >>= 4;
	}
	*p = '\0';
	ft_str_reverse(res);
	free(hex);
}

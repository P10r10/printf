/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 18:12:38 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/15 18:12:46 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_putnbr_u(unsigned int n, char *res)
{
	char	*p;

	p = res;
	while (n)
	{
		*p++ = n % 10 + '0';
		n /= 10;
	}
	*p = '\0';
	ft_str_reverse(res);
	return (res);
}

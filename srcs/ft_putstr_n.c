/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:37:12 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/18 16:37:31 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_putstr_n(char *s, size_t n)
{
	size_t	count;

	count = 0;
	while (*s && n--)
		count += ft_putchar(*s++);
	return (count);
}

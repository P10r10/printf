/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:12:56 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/13 18:13:14 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_putstr(char *s)
{
	size_t	count;

	count = 0;
	while (*s)
		count += ft_putchar(*s++);
	return (count);
}

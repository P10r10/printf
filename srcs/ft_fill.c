/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:38:22 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/18 16:39:13 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_fill(size_t n, char c)
{
	size_t	count;

	count = 0;
	while (n--)
	{
		ft_putchar(c);
		count++;
	}
	return (count);
}	

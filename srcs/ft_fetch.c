/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:37:57 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/25 19:40:13 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_fetch(const char *str, char *buf)
{
	str++;
	while (!ft_isspecifier(*str) && *str)
		*buf++ = *str++;
	if (*str != '\0')
	{
		*buf++ = *str;
		*buf = '\0';
	}
}

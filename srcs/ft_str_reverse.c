/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:13:44 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/13 18:14:34 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_str_reverse(char *str)
{
	char	*begin;
	char	*end;
	char	tmp;

	begin = str;
	end = str + (ft_strlen(str) - 1);
	while (begin < end)
	{
		tmp = *end;
		*end-- = *begin;
		*begin++ = tmp;
	}
}

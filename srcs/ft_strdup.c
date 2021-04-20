/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:15:02 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/13 18:15:18 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strdup(char *s)
{
	char	*res;
	char	*begin;

	res = (char *)malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	begin = res;
	while (*s)
		*res++ = *s++;
	*res = '\0';
	return (begin);
}

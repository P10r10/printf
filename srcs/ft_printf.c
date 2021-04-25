/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:01:24 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/25 19:41:57 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*update_flags_2(t_flags *flag, char *s)
{
	while (*s == '#' || *s == '0' || *s == '-'
		   || *s == ' ' || *s == '+')
	{
		if (*s == '#')
			flag->sharp = 1;
		if (*s == '0')
			flag->zero = 1;
		if (*s == '-')
			flag->minus = 1;
		if (*s == ' ')
			flag->space = 1;
		if (*s == '+')
			flag->plus = 1;
		s++;
	}
	return (s);
}

static void	update_flags(t_flags *flag, char *s)
{
	s = update_flags_2(flag, s);
	if (*s == '*')
	{
		flag->placehold_w = 1;
		s++;
	}
	else
		while (ft_isdigit(*s))
			flag->width = flag->width * 10 + *s++ - '0';
	if (*s == '.')
	{
		s++;
		flag->precision = 0;
		if (*s == '*')
		{
			flag->placehold_p = 1;
			s++;
		}
		else
			while (ft_isdigit(*s))
				flag->precision = flag->precision * 10 + *s++ - '0';
	}
	if (ft_isspecifier(*s))
		flag->type = *s;
}

static void	init_flags(t_flags *flag)
{
	flag->sharp = 0;
	flag->zero = 0;
	flag->space = 0;
	flag->precision = -1;
	flag->type = 0;
	flag->width = 0;
	flag->minus = 0;
	flag->placehold_w = 0;
	flag->placehold_p = 0;
}

static size_t	treat_types(t_flags *flag, va_list ap, char *buf)
{
	size_t	count;

	count = 0;
	if (flag->type == 'c')
		count = ft_treat_type_c(flag, ap);
	if (flag->type == 's')
		count = ft_treat_type_s(flag, ap, 0);
	if (flag->type == 'p')
		count = ft_treat_type_p(flag, ap, buf, 0);
	if (flag->type == 'd' || flag->type == 'i')
		count = ft_treat_type_d(flag, ap, buf, 0);
	if (flag->type == 'u')
		count = ft_treat_type_u(flag, ap, buf);
	if (flag->type == '%')
		count = ft_treat_type_perc(flag);
	if (flag->type == 'x')
		count = ft_treat_type_x(flag, ap, buf, 'x');
	if (flag->type == 'X')
		count = ft_treat_type_x(flag, ap, buf, 'X');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_flags	flag;
	size_t	count;
	char	*buffer;

	count = 0;
	buffer = malloc(20);
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
			count += ft_putchar(*str);
		else
		{
			ft_fetch(str, buffer);
			str += ft_strlen(buffer);
			init_flags(&flag);
			update_flags(&flag, buffer);
			count += treat_types(&flag, ap, buffer);
		}
		str++;
	}
	va_end(ap);
	free(buffer);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:01:24 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/20 18:30:15 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*static int	analyse_str(const char *str, va_list ap)
			if (*str == 'u')
				ft_putstr(ft_putnbr_u(va_arg(ap, int), buffer));
			if (*str == 'x')
				ft_putstr(ft_putnbr_h(va_arg(ap, int), buffer, 'x'));
			if (*str == 'X')
				ft_putstr(ft_putnbr_h(va_arg(ap, int), buffer, 'X'));
}*/

void update_flags(t_flags *flag, char *s)
{
//parte 1 da maq. de estados
	while (*s == '#' || *s == '0' || *s == '-' ||
			*s == ' ' || *s == '+')
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
//parte 2 da maq. de estados
	if (*s == '*')
	{
		flag->placehold_w = 1;
		s++;
	}
	else
		while (ft_isdigit(*s))
		{
			flag->width = flag->width * 10 + *s - '0';
			s++;	
		}
//parte 3 da maq. de estados
	if(*s == '.')
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
			{
				flag->precision = flag->precision * 10 + *s - '0';
				s++;	
			}
	}
//parte 4 da maq. de estados para bonus COMPLETAR
//estamos no type
	if (ft_isspecifier(*s))
		flag->type = *s;
}

void	init_flags(t_flags *flag)
{
	//falta inicializar o resto
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

void	fetch(const char *str, char *buf)
{
	str++;
	while (!ft_isspecifier(*str) && *str)
		*buf++ = *str++;
	//*str tem specifier OU '/0' //tratar
	if (*str != '\0')
	{
		*buf++ = *str;
		*buf = '\0';
	}
}
void fill(size_t n, char c)
{
	while (n--)
		ft_putchar(c);
}

size_t	treat_types(t_flags *flag, va_list ap, char *buf)//TIRAR ELSES ??
{
	size_t count;

	count = 0;
	if(flag->type == 'c')
		count = ft_treat_type_c(flag, ap);
	if(flag->type == 's')
		count = ft_treat_type_s(flag, ap, 0);
	if(flag->type == 'p')
		count = ft_treat_type_p(flag, ap, buf, 0);
	if(flag->type == 'd' || flag->type == 'i')
		count = ft_treat_type_d(flag, ap, buf, 0, 0);
	if(flag->type == 'u' || flag->type == 'i')
		count = ft_treat_type_u(flag, ap, buf, 0, 0);
	if(flag->type == '%')
		count = ft_treat_type_perc();
	if(flag->type == 'x')
		count = ft_treat_type_x(flag, ap, buf);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_flags flag;
	size_t count;
	char *buffer;

	count = 0;
	buffer = malloc(20);//rever 20?
	if (!buffer)
		return (-1);
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar(*str);
			count++;
		}
		else
			{
				fetch(str, buffer);
				str += ft_strlen(buffer);
				init_flags(&flag);
				update_flags(&flag, buffer);
				count += treat_types(&flag, ap, buffer);
			}
		str++;
	}
	va_end(ap);
	free(buffer);
	return (count);//count
}

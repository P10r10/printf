/*HEADER 42*/

#include "../includes/ft_printf.h"

size_t	ft_treat_type_x(t_flags *flag, va_list ap, char *buf)//precision digits //width espaco ocupado
{
	size_t count;
	char *s;
	int len;
	
	count = 0;
	if (flag->placehold_w)
		flag->width = va_arg(ap, int);
	if (flag->placehold_p)
		flag->precision = va_arg(ap, int);
	if (flag->width < 0)
	{
		flag->minus = 1;
		flag->width *= -1;
	}
	s = ft_putnbr_h(va_arg(ap, int), buf, 'x');
	len = ft_strlen(s);
	if (flag->minus)
	{
		if (flag->precision > len)
			count += ft_fill(flag->precision - len, '0');
		count += ft_putstr_n(s, flag->precision);
	}
	if (flag->precision > 0 && (flag->width - flag->precision) > 0)
		count += ft_fill(flag->width - flag->precision, ' ');
	/*else
		if (flag->width > len)
			count += ft_fill(flag->width - len, ' ');*/
	if (!(flag->minus))
	{
		if (flag->precision > len)
			count += ft_fill(flag->precision - len, '0');
		count += ft_putstr_n(s, flag->precision);
	}
	return (count);
}
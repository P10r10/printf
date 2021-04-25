/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsantia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:11:01 by alsantia          #+#    #+#             */
/*   Updated: 2021/04/20 18:30:16 by alsantia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flags
{
	int		sharp;
	int		zero;
	int		minus;
	int		space;
	int		plus;
	int		width;
	int		placehold_w;
	int		placehold_p;
	int		precision;
	char	type;
}	t_flags;

size_t	ft_fill(size_t n, char c);
int		ft_isspecifier(int c);
int		ft_isdigit(int c);
int		ft_printf(const char *str, ...);
size_t	ft_putchar(char c);
void	ft_putnbr(int n, char *res, int is_neg, int mod);
void	ft_putnbr_u(unsigned int nb, char *res);
void	ft_putnbr_h(unsigned long nb, char *res, char c);
size_t	ft_putstr(char *s);
size_t	ft_putstr_n(char *s, size_t n);
void	ft_str_reverse(char *str);
char	*ft_strdup(char *s);
size_t	ft_strlen(char *s);
size_t	ft_treat_type_c(t_flags *flag, va_list ap);
size_t	ft_treat_type_d(t_flags *flag, va_list ap, char *buf, size_t count, int is_neg);
size_t	ft_treat_type_p(t_flags *flag, va_list ap, char *buf, size_t count);
size_t	ft_treat_type_perc();
size_t	ft_treat_type_s(t_flags *flag, va_list ap, size_t count);
size_t	ft_treat_type_x(t_flags *flag, va_list ap, char *buf);
size_t	ft_treat_type_u(t_flags *flag, va_list ap, char *buf);

#endif

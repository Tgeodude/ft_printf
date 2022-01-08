/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:19:41 by tgeodude          #+#    #+#             */
/*   Updated: 2022/01/08 23:32:13 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_xx(unsigned int str, char chr)
{
	char	*string;
	int		count;
	int		val;

	if (str == 0)
		return (write(1, "0", 1));
	count = -1;
	string = (char *)malloc(lenght_str(str) + 1);
	while (count++, str)
	{
		val = str % 16;
		str /= 16;
		string[count] = calcul_hex(val, chr);
	}
	string[count] = '\0';
	write_hex(string, count);
	free(string);
	return (count);
}

int	ft_print_u(unsigned int a)
{
	if (a < 0)
		return (ft_putnbr((4294967295 + 1) - a));
	return (ft_putnbr(a));
}

int	ft_pointer(unsigned long point)
{
	write(1, "0x", 2);
	if (point == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	else
		return (ft_print_point(point, 'a') + 2);
}

int	line_analis(const char *str, va_list ap)
{
	if (*str == 'c')
		return (ft_putchar((char) va_arg(ap, int)));
	if (*str == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (*str == 'i' || *str == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	if (*str == 'x')
		return (ft_print_xx(va_arg(ap, unsigned int), 'a'));
	if (*str == 'X')
		return (ft_print_xx(va_arg(ap, unsigned int), 'A'));
	if (*str == 'u')
		return (ft_print_u(va_arg(ap, unsigned int)));
	if (*str == 'p')
		return (ft_pointer(va_arg(ap, unsigned long)));
	if (*str == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			count += line_analis(++str, ap);
		else
		{
			write(1, str, 1);
			count++;
		}
		str++;
	}
	va_end(ap);
	return (count);
}

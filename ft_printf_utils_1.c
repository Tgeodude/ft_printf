/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:27:02 by tgeodude          #+#    #+#             */
/*   Updated: 2022/01/08 23:27:43 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	size_t	i;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = -1;
	if (s)
		while (s[++i])
			write(1, &s[i], 1);
	return (i);
}

int	value_integer(long long int val)
{
	long long int	j;
	int				count;

	j = val;
	count = -1;
	if (val == 0)
		return (1);
	while (count++, j)
		j /= 10;
	return (count);
}

long long int	ft_number(long long int k)
{
	long long int	j;

	j = 1;
	while (k)
	{
		k /= 10;
		j *= 10;
	}
	return (j / 10);
}

int	ft_putnbr(long long int val)
{
	long long int	k;
	long long int	i;
	long long int	a;
	int				count;

	i = val;
	count = value_integer(i);
	if (i < 0)
	{
		i *= -1;
		ft_putchar('-');
	}
	k = ft_number(i);
	while (k >= 10)
	{
		a = ((i / k) % 10);
		ft_putchar((a + '0'));
		k /= 10;
	}
	if (k < 10)
		ft_putchar(((i % 10) + '0'));
	if (val < 0)
		return (count + 1);
	return (count);
}

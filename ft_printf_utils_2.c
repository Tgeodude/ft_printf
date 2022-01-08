/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:30:05 by tgeodude          #+#    #+#             */
/*   Updated: 2022/01/08 23:33:11 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	lenght_str(unsigned long str)
{
	int	count;

	count = -1;
	while (count++, str > 0)
		str /= 16;
	return (count);
}

char	calcul_hex(long long int val, char chr)
{
	if (val >= 10)
		return ((val - 10) + chr);
	return (val + '0');
}

void	write_hex(char *string, int count)
{
	while (--count >= 0)
		write(1, &string[count], 1);
}

int	ft_print_point(unsigned long str, char chr)
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

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

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

int	value_integer(int val)
{
	int	j;
	int	count;

	j = val;
	count = -1;
	if (val == 0)
		return (1);
	while (count++, j)
		j /= 10;
	return (count); 
}

static long long int	ft_number(long long int k)
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
	int		a;

	i = val;
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
	return (value_integer(val));

}

int lenght_str(unsigned long str)
{
	int	count;

	count = -1;
	while (count++, str > 0)
		str /= 16;
	return (count);
}

char	calcul_xX(int val, char chr)
{
	if (val >= 10)
		return ((val - 10) + chr);
	return (val + '0');
}

void write_xX(char *string, int count)
{
	while (--count >= 0)
		write(1, &string[count], 1);
}

int	ft_print_xX(unsigned long str, char chr)
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
		string[count] = calcul_xX(val, chr);
	}
	string[count] = '\0';
	write_xX(string, count);
	free(string);
	return (count);
}

int	ft_print_u(int a)
{
	if (a < 0)
		return (ft_putnbr(4294967296 + a));
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
		return (ft_print_xX(point, 'a') + 2);
}

int	line_analis(const char * str, int count, va_list ap)
{
	if (*str == 'c')
		return (ft_putchar((char) va_arg(ap, int)));
	if (*str == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (*str == 'i' || *str == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	if (*str == 'x')
		return (ft_print_xX(va_arg(ap, unsigned long), 'a'));
	if (*str == 'X')
		return (ft_print_xX(va_arg(ap, unsigned long), 'A'));
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

int	ft_printf(const char * str, ...) {

	va_list	ap;
	char	c;
	int	count;
	
	count = 0;
	va_start(ap, str);
	while (*str) 
	{
		if (*str == '%')
		{
			count += line_analis(++str, count, ap);
		}
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

int	main(void) 
{
	int		a;
	char	*s;
	char 	*s2;

	s2 = NULL;
	a = 2147483647;
	ft_printf("%d\n", ft_printf("%p%s%c%x%X%u%d%i%%%%", &a, NULL, '0', 2147483647, 2147483647, 2147483647, 2147483647, 2147483647));
}

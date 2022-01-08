#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	size_t	i;

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


int	ft_putnbr(int val)
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

int	line_analis(const char * str, int count, va_list ap)
{
	if (*str == 'c')
		count += ft_putchar((char) va_arg(ap, int));
	if (*str == 's')
		count += ft_putstr(va_arg(ap, char *));
	if (*str == 'i')
		count += ft_putnbr(va_arg(ap, int));
	if (*str == '')
	if (*str == '%')
	{
		count++;
		write(1, "%", 1);
	}
	return (count);
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
			write(1, str, 1);
		count++;
		str++;

	}
	va_end(ap);
	return (count);

}

int	main(void) 
{
	char	a;
	char	*s;

	a = 'w';
	ft_printf("hello %c%s %i%%", a , "orld" , 100);
}

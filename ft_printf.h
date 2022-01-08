/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeodude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:24:17 by tgeodude          #+#    #+#             */
/*   Updated: 2022/01/08 23:31:41 by tgeodude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef  FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *str, ...);
int				line_analis(const char *str, va_list ap);
int				ft_pointer(unsigned long point);
int				ft_print_u(unsigned int a);
int				ft_print_xx(unsigned int str, char chr);
int				ft_print_point(unsigned long str, char chr);
int				ft_putnbr(long long int val);
long long int	ft_number(long long int k);
int				value_integer(long long int val);
int				ft_putstr(char *s);
int				ft_putchar(char c);
void			write_hex(char *string, int count);
char			calcul_hex(long long int val, char chr);
int				lenght_str(unsigned long str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:18:56 by mtocu             #+#    #+#             */
/*   Updated: 2023/12/01 16:03:46 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <stdint.h>
#include <limits.h>
/*
int	print_char(int c)
{
	return (write (1, &c, 1));
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (print_str("(null)"));
	while (*str)
	{
		print_char((int)*str);
		++count;
		++str;
	}
	return (count);
}*/

int	print_digit(long n, int base, int upper)
{
	int		count;
	char	*symbols;

	count = 0;
	if (upper == 0)
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		write (1, "-", 1);
		return (1 + print_digit(-n, base, upper));
	}
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_digit (n / base, base, upper);
		return (count + print_digit(n % base, base, upper));
	}
}

int	ft_len(unsigned long int x)
{
	int	i;

	i = 0;
	while (x > 0)
	{
		i++;
		x /= 16;
	}
	return (i);
}

int	ft_print_pointer(unsigned long int x)
{
	int	i;
	int	number[20];
	int	len;

	i = 0;
	if (x == 0)
		return (print_str("(nil)"));
	print_str("0x");
	len = ft_len(x);
	while (i < len)
	{
		number[i] = "0123456789abcdef"[x % 16];
		x /= 16;
		i++;
	}
	while (--i >= 0)
		print_char(number[i]);
	return (len + 2);
}

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)va_arg(ap, int), 10, 0);
	else if (specifier == 'x')
		count += print_digit((long)va_arg(ap, unsigned int), 16, 0);
	else if (specifier == 'X')
		count += print_digit((long)va_arg(ap, unsigned int), 16, 1);
	else if (specifier == 'u')
		count += print_digit((long)va_arg(ap, unsigned int), 10, 0);
	else if (specifier == 'p')
		count += ft_print_pointer(va_arg(ap, unsigned long int));
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write (1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

/*
int	main(void)
{
	int count;
	long long x = 123456;
	long long int *ptr = &x;
	count = printf(" %p ", ptr);
	printf(" The chars written are %d\n", count);
	count = ft_printf(" %p ", ptr);
	ft_printf(" the chars written are %d\n", count);
	return (0);
}*/

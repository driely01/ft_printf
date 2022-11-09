/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:36:12 by del-yaag          #+#    #+#             */
/*   Updated: 2022/11/08 15:36:14 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(const char *fmt, va_list args, int i, int len)
{
	len = 0;
	if (fmt[i] == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (fmt[i] == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (fmt[i] == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (fmt[i] == '%')
		len += ft_putchar('%');
	else if (fmt[i] == 'u')
		len += ft_putnbr(va_arg(args, unsigned int));
	else if (fmt[i] == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (fmt[i] == 'X')
		len += ft_putnbr_hex(va_arg(args, unsigned int), 'X');
	else if (fmt[i] == 'x')
		len += ft_putnbr_hex(va_arg(args, unsigned int), 'x');
	else if (fmt[i] == 'p')
	{
		len += ft_putstr("0x");
		len += ft_putnbr_hex(va_arg(args, unsigned long long), 'p');
	}
	else
		len += ft_putchar(fmt[i]);
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(args, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == 0)
				break ;
			len += ft_check(fmt, args, i, len);
		}
		else
			len += ft_putchar(fmt[i]);
		i++;
	}
	va_end(args);
	if (len < 0)
		return (-1);
	return (len);
}

// int	main(void)
// {
// 	char	str[] = "hello";
// 	char	*p;
// 	p = str;
// 	ft_printf("null string: %s\n", NULL);
// 	ft_printf("percent %%%\n");
// 	ft_printf("\n");
// 	ft_printf("unsigned int: %u\n", -12);
// 	ft_printf("integer is: %i\n", 333333);
// 	ft_printf("####################\n");
// 	ft_printf("string is: %s\n", str);
// 	ft_printf("%%\n");
// 	ft_printf("%\n");
// 	ft_printf("hexadecimal: %X\n", 1234567);
// 	ft_printf("hexadecimal: %x\n", 1234567);
// 	ft_printf("address: %p\n", p);
// 	ft_printf("\n");
// }
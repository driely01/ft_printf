/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:36:21 by del-yaag          #+#    #+#             */
/*   Updated: 2022/11/08 15:36:24 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(long long n);
int	ft_strlen(char *str);
int	ft_putnbr_hex(unsigned long long nb, int c);
int	ft_check(const char *fmt, va_list args, int i, int len);
int	ft_printf(const char *fmt, ...);

#endif

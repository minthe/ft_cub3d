/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:32:29 by vfuhlenb          #+#    #+#             */
/*   Updated: 2021/12/19 23:17:32 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_char(char c)
{
	return (write(1, &c, 1));
}

int	write_str(char *string)
{
	int	bytes;
	int	index;

	index = -1;
	bytes = 0;
	if (!string)
		return (write (1, "(null)", 6));
	while (string[++index])
		bytes += write (1, &string[index], 1);
	return (bytes);
}

int	specifier(const char *fmt, int i, va_list args)
{
	int	bytes;

	bytes = 0;
	if (fmt[i] == 'c')
		bytes = write_char(va_arg(args, int));
	else if (fmt[i] == 's')
		bytes = write_str(va_arg(args, char *));
	else if (fmt[i] == 'p')
		bytes = write_ptr(va_arg(args, unsigned long long), 0);
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		bytes = write_int(va_arg(args, int), 0);
	else if (fmt[i] == 'u')
		bytes = write_uint(va_arg(args, int), 0);
	else if (fmt[i] == 'x')
		bytes = write_hex(va_arg(args, int), 0);
	else if (fmt[i] == 'X')
		bytes = write_hexu(va_arg(args, int), 0);
	else if (fmt[i] == '%')
		bytes = write(1, "%", 1);
	return (bytes);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		index;
	int		sum_bytes;

	va_start(args, fmt);
	index = 0;
	sum_bytes = 0;
	while (fmt[index])
	{
		if (fmt[index] == '%')
		{
			sum_bytes += specifier(fmt, index + 1, args);
			index++;
		}
		else
			sum_bytes += write(1, &fmt[index], 1);
		index++;
	}
	va_end(args);
	return (sum_bytes);
}

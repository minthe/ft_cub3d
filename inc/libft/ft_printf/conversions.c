/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:14:28 by vfuhlenb          #+#    #+#             */
/*   Updated: 2021/12/19 23:17:40 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_ptr(unsigned long long n, int bytes)
{
	int	rem;

	if (bytes == 0)
		bytes += write(1, "0x", 2);
	if (n > 15)
		bytes = write_ptr(n / 16, bytes);
	rem = n % 16;
	bytes += write(1, &"0123456789abcdef"[rem], 1);
	return (bytes);
}

int	write_int(int n, int bytes)
{
	char	rem;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		bytes += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		bytes = write_int(n / 10, bytes);
	rem = n % 10 + '0';
	bytes += write(1, &rem, 1);
	return (bytes);
}

int	write_uint(unsigned int n, int bytes)
{
	char	rem;

	if (n < 0)
		return (0);
	if (n > 9)
		bytes = write_uint(n / 10, bytes);
	rem = n % 10 + '0';
	bytes += write(1, &rem, 1);
	return (bytes);
}

int	write_hex(unsigned int n, int bytes)
{
	int	rem;

	if (n < 0)
		return (0);
	if (n > 15)
		bytes = write_hex(n / 16, bytes);
	rem = n % 16;
	bytes += write(1, &"0123456789abcdef"[rem], 1);
	return (bytes);
}

int	write_hexu(unsigned int n, int bytes)
{
	int	rem;

	if (n < 0)
		return (0);
	if (n > 15)
		bytes = write_hexu(n / 16, bytes);
	rem = n % 16;
	bytes += write(1, &"0123456789ABCDEF"[rem], 1);
	return (bytes);
}

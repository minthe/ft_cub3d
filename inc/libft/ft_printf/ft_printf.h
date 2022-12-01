/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:33:01 by vfuhlenb          #+#    #+#             */
/*   Updated: 2021/12/19 22:54:27 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *fmt, ...);
int	specifier(const char *fmt, int i, va_list args);
int	write_char(char c);
int	write_str(char *chr);
int	write_hexu(unsigned int n, int bytes);
int	write_hex(unsigned int n, int bytes);
int	write_uint(unsigned int n, int bytes);
int	write_int(int n, int bytes);
int	write_ptr(unsigned long long n, int bytes);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 05:55:18 by oafidi            #+#    #+#             */
/*   Updated: 2025/02/03 23:58:20 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_next(const char *format, int index, va_list ap)
{
	if (format[index] == 'c')
		return (put_char(va_arg(ap, int)));
	if (format[index] == 's')
		return (put_str(va_arg(ap, char *)));
	if (format[index] == 'p')
		return (put_pointer(va_arg(ap, unsigned long)));
	if (format[index] == 'd' || format[index] == 'i')
		return (intformat(va_arg(ap, int)));
	if (format[index] == 'u')
		return (unsignedformat(va_arg(ap, unsigned int)));
	if (format[index] == 'x' || format[index] == 'X')
	{
		if (format[index] == 'x')
			return (hexaformat(va_arg(ap, unsigned int), "0123456789abcdef"));
		else
			return (hexaformat(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	}
	if (format[index] == '%')
		return (put_char('%'));
	else
		return (put_char(format[index]));
}

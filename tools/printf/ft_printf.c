/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:43:19 by oafidi            #+#    #+#             */
/*   Updated: 2025/02/04 00:55:51 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start (ap, format);
	count = 0;
	i = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
		{
			count += write (1, &format[i], 1);
			i++;
		}
		if (format[i] == '%' && format[i + 1] == '\0')
			break ;
		if (format[i] == '%' && format[i + 1])
		{
			count = count + check_next(format, i + 1, ap);
			i += 2;
		}
	}
	return (va_end(ap), count);
}

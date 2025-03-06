/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:23:14 by oafidi            #+#    #+#             */
/*   Updated: 2025/02/04 00:57:05 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		check_next(const char *format, int index, va_list ap);
void	put_hexa(unsigned long nbr, const char *base, int *a);
int		ft_printf(const char *format, ...);
int		put_char(char c);
void	put_nbr(int n, int *a);
int		put_str(char *str);
int		put_pointer(unsigned long p);
int		unsignedformat(int d);
int		hexaformat(unsigned int p, const char *str);
void	put_unsigned(unsigned int n, int *a);
int		intformat(int d);

#endif

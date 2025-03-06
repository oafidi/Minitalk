/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointerformat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:32:10 by oafidi            #+#    #+#             */
/*   Updated: 2025/02/04 00:19:28 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_pointer(unsigned long p)
{
	int	i;

	i = 0;
	put_char('0');
	put_char('x');
	i = i + 2;
	put_hexa(p, "0123456789abcdef", &i);
	return (i);
}

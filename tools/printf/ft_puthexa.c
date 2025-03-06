/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 05:57:00 by oafidi            #+#    #+#             */
/*   Updated: 2025/02/03 23:44:35 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_hexa(unsigned long nbr, const char *base, int *a)
{
	if (nbr < 16)
	{
		put_char(base[nbr]);
		*a += 1;
	}
	else
	{
		put_hexa(nbr / 16, base, a);
		put_char(base[nbr % 16]);
		*a += 1;
	}
}

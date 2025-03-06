/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexaformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:51:07 by oafidi            #+#    #+#             */
/*   Updated: 2024/11/22 18:02:31 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_hexa_uint(unsigned int nbr, const char *base, int *a)
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

int	hexaformat(unsigned int p, const char *str)
{
	int	i;

	i = 0;
	put_hexa_uint(p, str, &i);
	return (i);
}

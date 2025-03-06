/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:38:47 by oafidi            #+#    #+#             */
/*   Updated: 2025/02/04 00:52:13 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mandatory/minitalk.h"

static int	is_space(char c)
{
	if (c == 32 || (c <= 13 && c >= 9))
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		signe;
	long	nb;
	long	valeur_precedente;

	i = 0;
	nb = 0;
	signe = 1;
	while (is_space(str[i]) == 1)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			signe *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		valeur_precedente = nb;
		nb = nb * 10 + str[i] - 48;
		if (nb / 10 != valeur_precedente)
			return (-1);
		i++;
	}
	return (nb * signe);
}

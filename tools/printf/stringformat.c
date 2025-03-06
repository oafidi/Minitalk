/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:26:14 by oafidi            #+#    #+#             */
/*   Updated: 2024/11/22 18:01:38 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (put_str("(null)"));
	while (str[i])
	{
		put_char(str[i]);
		i++;
	}
	return (i);
}

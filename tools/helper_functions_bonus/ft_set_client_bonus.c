/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_client_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 04:56:20 by oafidi            #+#    #+#             */
/*   Updated: 2025/02/04 00:11:58 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../bonus/minitalk_bonus.h"

void	ft_set_client(t_client *client)
{
	int	i;

	i = 0;
	client -> current_bit = 0;
	client -> current_char = 0;
	client -> pid = 0;
	while (i < 8)
		client -> unicode_buffer[i++] = 0;
	client -> unicode_index = 0;
	client -> unicode_size = 0;
}

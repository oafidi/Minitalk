/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 04:56:20 by oafidi            #+#    #+#             */
/*   Updated: 2025/02/04 00:52:25 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mandatory/minitalk.h"

void	ft_set_client(t_client *client)
{
	client -> current_bit = 0;
	client -> current_char = 0;
	client -> pid = 0;
}

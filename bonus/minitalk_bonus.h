/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 03:29:31 by oafidi            #+#    #+#             */
/*   Updated: 2025/02/04 00:56:45 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../tools/printf/ft_printf.h"

typedef struct s_client
{
	int				pid;
	char			current_char;
	int				current_bit;
	unsigned char	unicode_buffer[8];
	int				unicode_size;
	int				unicode_index;
}	t_client;

long	ft_atoi(const char *str);
void	ft_set_client(t_client *client);
void	*ft_memset(void *b, int c, size_t len);

#endif

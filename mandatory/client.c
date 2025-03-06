/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 03:29:48 by oafidi            #+#    #+#             */
/*   Updated: 2025/02/04 01:17:11 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_byte(unsigned char c, int pid)
{
	int	i;
	int	sig;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			sig = SIGUSR2;
		else
			sig = SIGUSR1;
		if (kill(pid, sig) < 0)
		{
			ft_printf("\033[1;31mInvalid PID!! \n\033[0m");
			exit(1);
		}
		i++;
		usleep(100);
		usleep(100);
		usleep(100);
	}
}

static int	ft_check_pid(const char *str)
{
	unsigned long	i;
	long			pid;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	pid = ft_atoi(str);
	if (pid > INT_MAX || pid <= 0)
		return (-1);
	return (pid);
}

int	main(int argc, char **argv)
{
	int				pid;
	unsigned int	i;

	if (argc != 3 || !argv[2][0] || !argv[1][0])
	{
		ft_printf("\033[1;31mInvalid Arguments !! \n\033[0m");
		return (1);
	}
	pid = ft_check_pid(argv[1]);
	if (pid < 0)
	{
		ft_printf("\033[1;31mInvalid PID !! \n\033[0m");
		return (1);
	}
	i = 0;
	while (argv[2][i])
		ft_send_byte(argv[2][i++], pid);
	ft_send_byte('\0', pid);
	ft_printf("\033[1;32mMessage Sent Successfully \033[0m\n");
	return (0);
}

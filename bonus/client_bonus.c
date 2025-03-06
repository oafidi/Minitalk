/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 03:29:48 by oafidi            #+#    #+#             */
/*   Updated: 2025/02/04 00:53:25 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_server_pid;

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
		usleep(200);
		usleep(200);
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

static void	sig_handler(int signum, siginfo_t *info, void *con)
{
	(void)signum;
	(void)con;
	if (g_server_pid != info->si_pid)
		return ;
	else
	{
		ft_printf("\033[1;32mMessage Received Successfully \033[0m\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	unsigned int		i;
	struct sigaction	sa;

	if (argc != 3 || !argv[2][0] || !argv[1][0])
	{
		ft_printf("\033[1;31mInvalid Arguments !! \n\033[0m");
		return (1);
	}
	g_server_pid = ft_check_pid(argv[1]);
	if (g_server_pid < 0)
	{
		ft_printf("\033[1;31mInvalid PID !! \n\033[0m");
		return (1);
	}
	i = 0;
	while (argv[2][i])
		ft_send_byte(argv[2][i++], g_server_pid);
	ft_send_byte('\0', g_server_pid);
	ft_printf("\033[1;32mMessage Sent Successfully \033[0m\n\n");
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		pause();
	return (0);
}

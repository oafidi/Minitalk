/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 03:29:39 by oafidi            #+#    #+#             */
/*   Updated: 2025/02/04 01:43:01 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int signum, siginfo_t *info, void *con)
{
	static t_client	client;

	(void) con;
	if (client.pid != 0 && (client.pid != info->si_pid))
		ft_set_client(&client);
	if (client.pid == 0)
		client.pid = info->si_pid;
	if (signum == SIGUSR2)
		client.current_char |= (1 << client.current_bit);
	client.current_bit++;
	if (client.current_bit == 8)
	{
		if (client.current_char == '\0')
		{
			ft_printf("\n");
			ft_set_client(&client);
		}
		else
			ft_printf("%c", client.current_char);
		client.current_bit = 0;
		client.current_char = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("\033[1;31mInvalid Arguments !!\n\033[0m");
		return (1);
	}
	ft_printf("\033[1;33mThis Is The Server PID: %d\n\033[0m", getpid());
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

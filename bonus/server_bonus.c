/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oafidi <oafidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 03:29:39 by oafidi            #+#    #+#             */
/*   Updated: 2025/02/04 02:21:11 by oafidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	check_unicode(unsigned char c)
{
	if (c < 0b10000000)
		return (1);
	else if ((c & 0b11100000) == 0b11000000)
		return (2);
	else if ((c & 0b11110000) == 0b11100000)
		return (3);
	else if ((c & 0b11111000) == 0b11110000)
		return (4);
	else
		return (0);
}

static void	handle_unicode_character(t_client *client)
{
	if (client->unicode_index == 0)
		client->unicode_size = check_unicode(client->current_char);
	client->unicode_buffer[client->unicode_index++] = client->current_char;
	if (client->unicode_index == client->unicode_size)
	{
		client->unicode_buffer[client->unicode_index] = '\0';
		ft_printf("%s", client->unicode_buffer);
		ft_memset(client->unicode_buffer, 0, sizeof(client->unicode_buffer));
		client->unicode_index = 0;
		client->unicode_size = 0;
	}
}

static void	handle_end_of_message(t_client *client)
{
	if (client->current_char == '\0')
	{
		ft_printf("\n");
		usleep(300);
		usleep(300);
		if (kill(client->pid, SIGUSR1))
			ft_printf("\033[1;31mClient Was Dead !!\n\033[0m");
		ft_set_client(client);
	}
}

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
		handle_unicode_character(&client);
		handle_end_of_message(&client);
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

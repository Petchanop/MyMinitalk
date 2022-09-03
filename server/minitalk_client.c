/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:57:49 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/03 21:49:44 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_char_to_server(unsigned char c, int server_pid)
{
	unsigned char	bit;

	bit = 128;
	while (bit)
	{
		if (bit & c)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				return (0);
		}
		bit >>= 1;
		usleep(100);
	}
	return (1);
}

static void	ft_sighandler(int signum)//, siginfo_t *info, void *context)
{
	static int				data_index = 8;
	static unsigned char	bit = 0;

	if (data_index > 0)
	{
		data_index--;
		if (signum == SIGUSR1)
			bit += 1 << data_index;
		else
			bit += 0 << data_index;
	}
	if (data_index == 0)
	{
		if (bit == 0)
		{
			write(1, "\n", 2);
			return ;
		}
		write(1, &bit, 1);
		data_index = 8;
		bit = 0;
	}
}

static void	ft_response(int signum, siginfo_t *info, void *context)
{
	int	i;

	i = 0;
	ft_sighandler(signum);
	if (signum || context)
	{
		ft_printf("RECEIVE signal by pid : %d", info->si_pid);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	pid_t				process_id;
	int					i;
	struct sigaction	server_sig;

	i = 0;
	if (argc == 3)
	{
		process_id = ft_atoi(argv[1]);
		while (argv[2][i])
			send_char_to_server(argv[2][i++], process_id);
		send_char_to_server(0, process_id);
	}
	server_sig.sa_handler = ft_sighandler;
	server_sig.sa_flags = 0;
	server_sig.sa_sigaction = ft_response;
	sigemptyset(&server_sig.sa_mask);
	sigaction(SIGUSR1, &server_sig, NULL);
	sigaction(SIGUSR2, &server_sig, NULL);
	while (1)
		usleep(1);
	return (0);
}

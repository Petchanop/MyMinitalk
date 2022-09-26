/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:57:49 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/26 15:19:18 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_sigerror(void)
{
	ft_printf("Fail to send signal\n");
	exit(0);
}

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

static void	ft_sighandler(int signum, siginfo_t *info, void *context)
{
	if (signum == SIGUSR1 && info->si_pid && context)
	{
		usleep(2000);
		ft_printf("server %d ", info->si_pid);
		ft_printf("already receive signal from client.\n");
		exit(0);
	}
}

static void	ft_response(int signum, siginfo_t *info, void *context)
{
	ft_sighandler(signum, info, context);
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
		{
			if (send_char_to_server(argv[2][i++], process_id) == 0)
				handle_sigerror();
		}
		send_char_to_server(0, process_id);
	}
	usleep(1000);
	server_sig.sa_flags = SA_SIGINFO | SA_RESTART;
	server_sig.sa_sigaction = &ft_response;
	sigaction(SIGUSR1, &server_sig, NULL);
	sigaction(SIGUSR2, &server_sig, NULL);
	sigemptyset(&server_sig.sa_mask);
	while (1)
		usleep(1);
	return (0);
}

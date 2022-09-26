/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:39:01 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/26 15:18:27 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_sigerror(void)
{
	ft_printf("Fail to send signal\n");
	exit(0);
}

static void	ft_sighandler(int signum, siginfo_t *info, void *context)
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
		if (bit == 0 || !context)
		{
			usleep(2000);
			if (kill(info->si_pid, SIGUSR1) == -1)
				handle_sigerror();
			write(1, "\n", 2);
			ft_printf("receive signal from client %d.\n", info->si_pid);
		}
		write(1, &bit, 1);
		data_index = 8;
		bit = 0;
	}
}

static void	ft_response(int signum, siginfo_t *info, void *context)
{
	ft_sighandler(signum, info, context);
}

void	ft_getpid(void)
{
	ft_printf("PID : %d\n", getpid());
}

int	main(void)
{
	struct sigaction	client_sig;

	client_sig.sa_flags = SA_SIGINFO | SA_RESTART;
	client_sig.sa_sigaction = &ft_response;
	ft_getpid();
	sigaction(SIGUSR1, &client_sig, NULL);
	sigaction(SIGUSR2, &client_sig, NULL);
	sigemptyset(&client_sig.sa_mask);
	while (1)
		usleep(1);
}

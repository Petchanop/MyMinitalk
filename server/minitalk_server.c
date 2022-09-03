/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:39:01 by npiya-is          #+#    #+#             */
/*   Updated: 2022/09/03 21:36:25 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	recieve;

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

static void	ft_sighandler(int signum, siginfo_t *info)
{
	static int				data_index = 8;
	static unsigned char	bit = 0;
	char					*str;
	int						i;

	i = 0;
	str = "RECEIVE signal by pid :";
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
		if (bit == 0)// && !info->si_pid)
		{
			write(1, "\n", 2);
			usleep(1000);
			while ((i < 5) & str[i])
			{
				send_char_to_server(str[i], info->si_pid);
				i++;
			}
			send_char_to_server(0, info->si_pid);
		}
		write(1, &bit, 1);
		data_index = 8;
		bit = 0;
	}
}

static void	ft_response(int signum, siginfo_t *info, void *context)
{
	ft_sighandler(signum, info);
	if (!signum || !context )
		ft_printf("\ncomplete %d", info->si_pid);
}

void	ft_getpid(void)
{
	ft_printf("PID : %d\n", getpid());
}

int	main(void)
{
	struct sigaction client_sig;
   // client_sig.sa_handler = ft_sighandler;
   client_sig.sa_flags = SA_SIGINFO;
   client_sig.sa_sigaction = ft_response; 
   //struct sigaction client_sig2;
	ft_getpid();
	//signal(SIGUSR1, ft_sighandler);
	//signal(SIGUSR2, ft_sighandler);
	sigaction(SIGUSR1, &client_sig, NULL);
	sigaction(SIGUSR2, &client_sig, NULL);
	while (1)
		usleep(1);
}
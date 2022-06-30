/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <npiya-is@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:39:01 by npiya-is          #+#    #+#             */
/*   Updated: 2022/06/30 15:27:14 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void    ft_sighandler(int signum)//, int data_index)//, siginfo_t *info, void *context)
{
    static int data_index = 8; 
    static unsigned char   bit = 0;

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
        write(1, &bit, 1);
        data_index = 8;
        bit = 0;
    }
}

void    ft_getpid(void)
{
    ft_printf("PID : %d\n",getpid());
}

int main(void)
{
    ft_getpid();
    signal(SIGUSR1, ft_sighandler);
    signal(SIGUSR2, ft_sighandler);
    while (1)
        usleep(1);
}


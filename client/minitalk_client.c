/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <npiya-is@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:57:49 by npiya-is          #+#    #+#             */
/*   Updated: 2022/06/30 15:34:35 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int send_char_to_server(unsigned char c, int server_pid)
{
    unsigned char   bit;

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

int main(int argc, char **argv)
{
    pid_t   process_id;
    int i;

    i = 0;
    if (argc == 3)
    {
        process_id = ft_atoi(argv[1]);
        while (argv[2][i])
            send_char_to_server(argv[2][i++], process_id);
    }
    return (0);
}


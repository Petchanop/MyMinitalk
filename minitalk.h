/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <npiya-is@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:39:30 by npiya-is          #+#    #+#             */
/*   Updated: 2022/06/29 14:37:02 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define    MINITALK_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <limits.h>
#include "ft_printf/libft/libft.h"
#include "ft_printf/srcs/ft_printf.h"

typedef struct s_data
{
    char            *buffer;
    unsigned char   c;
    int             index;
    int             client_pid;
}               t_data;

#endif


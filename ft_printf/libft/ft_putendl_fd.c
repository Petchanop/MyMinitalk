/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:59:52 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/19 17:49:53 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, &(*s), 1);
		s++;
	}
	write(fd, "\n", 1);
}
/*
int	main(void)
{
	int fd = open("text", O_WRONLY | O_CREAT | O_TRUNC);
	ft_putendl_fd("change", fd);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:50:56 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/19 17:50:04 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

void	ft_putnbr_fd(int nb, int fd)
{
	int		mod;
	char	*num;

	mod = nb % 10;
	num = "0123456789";
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		write(fd, "-", 1);
		nb *= -1;
		ft_putnbr_fd(nb, fd);
	}
	else if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(mod, fd);
	}
	else if (nb <= 9 && nb >= 0)
		write(fd, &num[nb], 1);
}
/*
void	ft_putnbr_fd(int n, int fd)
{

	while (*num)
	{
		write(fd, &(*num), 1);
		num++;
	}
}

int	main(void)
{
	int fd = open("number", O_WRONLY | O_CREAT);
	ft_putnbr_fd(100, fd);
	ft_putnbr_fd(-100, fd);
	ft_putnbr_fd(10011, fd);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:04:04 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/21 02:18:34 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mem, int c, size_t n);

void	ft_bzero(void *b, size_t len)
{
	ft_memset(b, 0, len);
}
/*
#include <string.h>

int	main(void)
{
//	char	mem[11] = "test bzero";
	char	ft_b[11] = "test bzero";
//	bzero(mem , 5 * sizeof(char));
	ft_bzero(ft_b, 5 * sizeof(char));
//	printf("bzero : %s\n",mem);
	printf("ft    : %s\n",ft_b);
	return (0);
}*/

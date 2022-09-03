/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 13:23:23 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/21 02:20:15 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mem, int c, size_t n)
{
	unsigned char	*pmem;

	pmem = mem;
	while (n-- != 0)
		*pmem++ = c;
	return (mem);
}
/*
#include <string.h>

int	main(void)
{
	char	mem[15] = "test ft_memset";
	char	ft_mem[15] = "test ft_memset";
	memset(mem, 'A', 5 * sizeof(char));
	ft_memset(ft_mem, 'A', 5 * sizeof(char));
	printf("memset	  : %s\n", mem);
	printf("ft_memset : %s\n", ft_mem);
	printf("memset	  : %s\n", (char *)memset(mem, 98, 20 * sizeof(char)));
	printf("ft_memset : %s\n", (char *)ft_memset(mem, 98, 20 * sizeof(char)));
	printf("memset	  : %s\n", (char *)memset(mem, 99, 0 * sizeof(char)));
	printf("ft_memset : %s\n", (char *)ft_memset(mem, 9, 0* sizeof(char)));
	return (0);
}*/

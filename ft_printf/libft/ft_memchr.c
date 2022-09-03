/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:20:36 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/21 15:14:38 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *ptr, int c, size_t len)
{
	size_t		n;
	char const	*pptr;

	pptr = ptr;
	n = 0;
	while (n < len)
	{
		if ((unsigned char)pptr[n] == (unsigned char)c)
			return ((void *)&pptr[n]);
		n++;
	}
	return (NULL);
}
/*
#include <string.h>

int	main(void)
{
	char const	*sr = "search occurrance";
	printf("memchr    : %p\n", memchr(sr, 'o'+ 256, 15));
	printf("ft_memchr : %p\n", ft_memchr(sr, 'o' + 256, 15));
	printf("memchr    : %p\n", memchr("bonjour", 'b', 4));
	printf("ft_memchr : %p\n", ft_memchr("bonjour", 'b', 4));
	return (0);
}*/

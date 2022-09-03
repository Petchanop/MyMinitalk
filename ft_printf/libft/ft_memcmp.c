/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:28:02 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/21 18:06:45 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void const *s1, void const *s2, size_t n)
{
	char const	*p1;
	char const	*p2;

	p1 = s1;
	p2 = s2;
	while (n)
	{
		if ((unsigned char)*p1 != (unsigned char)*p2)
			return ((unsigned char)*p1 - (unsigned char)*p2);
		p1++;
		p2++;
		n--;
	}
	return (0);
}
/*
#include <string.h>

int	main(void)
{
	char const	*s1 = "test memcmp";
	char const	*s2 = "memcmp";
	char const	*s3 = "test ";

	printf("memcmp	  : %d\n",memcmp(s1, s2, 6 * sizeof(char)));
	printf("ft_memcmp : %d\n",ft_memcmp(s1, s2, 6 * sizeof(char)));
	printf("memcmp	  : %d\n",memcmp(s1, s3, 7 * sizeof(char)));
	printf("ft_memcmp : %d\n",ft_memcmp(s1, s3, 7 * sizeof(char)));

	memcmp("t\200","t\0",2);
	ft_memcmp("t\200","t\0",2);
	printf("%d\n",memcmp("t\200","t\0", 2));
	printf("%d\n",ft_memcmp("t\200", "t\0", 2));
	return (0);
}*/

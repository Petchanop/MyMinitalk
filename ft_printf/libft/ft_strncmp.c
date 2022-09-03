/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:28:44 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/21 18:21:35 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*

int	main(void)
{
	printf("ans : 0 , result : %d\n",ft_strncmp("test", "test", 5));
	printf("ans : 1 , result : %d\n",ft_strncmp("ut", "test", 2));
	printf("ans : 0 , result : %d\n",ft_strncmp("te", "test", 2));
	printf("ans : -1 , result : %d\n",ft_strncmp("test", "testh", 5));
	printf("ans : 1 , result : %d\n",ft_strncmp("abcefg", "abcdef", 5));
	return (0);
}*/

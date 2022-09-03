/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:34:39 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/21 14:56:14 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strchr(char const *p, int ch)
{
	char	c;
	int		i;

	c = ch;
	i = 0;
	while (p[i])
	{
		if (p[i] == c)
			return ((char *)(p + i));
		i++;
	}
	if (p[i] == c)
		return ((char *)(p + i));
	return (NULL);
}
/*
#include <string.h>

int	main(void)
{
	char const *p = "";
	char const *p1 = "test strchr";

	printf("strchr	  : %s\n", strchr(p, '\0'));
	printf("ft_strchr : %s\n", ft_strchr(p, '\0'));
	printf("strchr	  : %s\n", strchr(p1, '\0'));
	printf("ft_strchr : %s\n", ft_strchr(p1, '\0'));
	return (0);
}*/

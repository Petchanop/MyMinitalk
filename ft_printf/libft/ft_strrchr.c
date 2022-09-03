/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:42:21 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/21 02:23:31 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *p, int ch);

char	*ft_strrchr(char const	*cp, int ch)
{
	char	*save;
	char	c;

	if (ch == '\0')
		return (ft_strchr(cp, '\0'));
	save = NULL;
	while (*cp)
	{
		c = *cp;
		if (c == (unsigned char)ch)
			save = (char *)cp;
		cp++;
	}
	return (save);
}
/*
#include <string.h>

int	main(void)
{
	char const *cp = "test strrchr";

	printf("strrchr     : %s\n", strrchr(cp , 's'));
	printf("ft_strrchr  : %s\n", ft_strrchr(cp , 's'));
	printf("strrchr     : %s\n", strrchr(cp , 't'));
	printf("ft_strrchr  : %s\n", ft_strrchr(cp , 't'));
	printf("strrchr     : %s\n", strrchr(cp , 'r'));
	printf("ft_strrchr  : %s\n", ft_strrchr(cp , 'r'));
	printf("strrchr     : %s\n", strrchr(cp , 'a'));
	printf("ft_strrchr  : %s\n", ft_strrchr(cp , 'a'));
	return (0);
}*/

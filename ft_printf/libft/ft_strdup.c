/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:39:03 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/21 15:24:16 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

size_t	ft_strlen(char const *str);

void	*ft_memcpy(void *dst, void const *src, size_t len);

char	*ft_strdup(char const *str)
{
	char			*copy;
	unsigned int	len;

	len = (unsigned int)(ft_strlen(str) + 1);
	copy = malloc(len * sizeof(char));
	if (!(copy))
		return (NULL);
	ft_memcpy(copy, str, len);
	return (copy);
}
/*
#include <string.h>

int	main(void)
{
	char const	*str = "test strdup";
	char const	*ftr = "test strdup";
	printf("strdup		: %s\n",strdup(str));
	printf("ft_strdup	: %s\n",ft_strdup(ftr));
	printf("strdup		: %s\n",strdup(""));
	printf("ft_strdup	: %s\n",ft_strdup(""));
	printf("strdup		: %s\n",strdup("##"));
	printf("ft_strdup	: %s\n",ft_strdup("##"));
	return (0);
}*/

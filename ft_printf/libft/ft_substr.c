/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:57:34 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/21 18:40:23 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char const *str);

static size_t	ft_size(char const *s, unsigned int start, size_t len)
{
	if ((start + len) < ft_strlen(s))
		return (len + 1);
	return (ft_strlen(s) - start + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (start < ft_strlen(s))
	{
		sub = malloc((ft_size(s, start, len)) * sizeof(char));
		if (!sub)
			return (NULL);
		while (i < len && s[i + start])
		{
			sub[i] = s[i + start];
			i++;
		}
	}
	else
		sub = malloc(sizeof(char));
	if (!sub)
		return (NULL);
	sub[i] = '\0';
	return (sub);
}
/*

int	main(void)
{
	char const *s;

	s = "test ft_substr";
	unsigned int start = 0;
	size_t len = 5;
	printf("%s\n", ft_substr(s, start, len));
	return (0);
}*/

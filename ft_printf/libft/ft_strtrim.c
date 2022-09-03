/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:48:13 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/21 15:12:15 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char const *str);

char	*ft_strrchr(char const *p, int ch);

size_t	ft_tailindex(char const *s1, char const *set)
{
	size_t	j;

	j = ft_strlen(s1);
	while (ft_strrchr(set, s1[j]) && j)
		j--;
	return (j);
}

size_t	ft_headindex(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_strrchr(set, s1[i]) && s1[i])
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*spy;
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_headindex(s1, set);
	j = ft_tailindex(s1, set) + 1;
	k = 0;
	if (j != 0 && i < j && *s1)
	{
		spy = malloc(((j - i) + 1) * sizeof(char));
		if (!spy)
			return (NULL);
		while (i < j)
			spy[k++] = s1[i++];
		spy[k] = '\0';
		return (spy);
	}
	spy = malloc(sizeof(char));
	if (!spy)
		return (NULL);
	spy[0] = 0;
	return (spy);
}
/*
int	main(void)
{
	char * p = ft_strtrim("123", "");
	char * s = ft_strtrim("abcdba", "acb");
	char * str = ft_strtrim("tripouille", " x");
	printf("%s\n", p);
	printf("%s\n", s);
	printf("%s\n", str);
	return (0);
}*/

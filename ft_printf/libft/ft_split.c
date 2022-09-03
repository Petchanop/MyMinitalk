/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 03:08:55 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/21 17:45:23 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char const *str);

int	ft_charcmp(char c1, char c2)
{
	if (c1 == c2)
		return (1);
	return (0);
}

static size_t	ft_size(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < ft_strlen(s) && *(s + i))
	{
		while (ft_charcmp(*(s + i), c) && *(s + i))
			i++;
		if (!ft_charcmp(*(s + i), c) && *(s + i))
			j++;
		while (!ft_charcmp(*(s + i), c) && *(s + i))
			i++;
	}
	return (j);
}

char	*ft_trim(char const *s, size_t start, size_t n)
{
	char	*spy;
	size_t	i;

	spy = malloc((n + 1) * sizeof(char));
	if (!spy)
		return (NULL);
	i = 0;
	while (i < n && *(s + start))
	{
			spy[i] = *(s + start);
		i++;
		start++;
	}
	spy[i] = '\0';
	return (spy);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**spl;

	i = ft_size(s, c);
	spl = malloc((i + 1) * sizeof(char *));
	if (!spl)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s + j) && j < ft_strlen(s))
	{
		k = 0;
		while (ft_charcmp(*(s + j), c) && *(s + j))
			j++;
		while (!ft_charcmp(*(s + k + j), c) && *(s + k + j))
			k++;
		if (k != 0)
			spl[i++] = ft_trim(s, j, k);
		j = j + k;
	}
	spl[i] = NULL;
	return (spl);
}

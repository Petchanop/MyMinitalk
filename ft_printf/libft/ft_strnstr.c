/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:55:16 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/21 18:21:59 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char const *str);

int		ft_strncmp(char const *s1, char const *s2, size_t n);

char	*ft_strnstr(char const *str, char const *to_find, size_t slen)
{
	size_t	i;

	if (!*to_find)
		return ((char *)(str));
	if (ft_strlen(to_find) > slen || !*str)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		if (slen - i < ft_strlen(to_find))
			return (NULL);
		if (!ft_strncmp((str + i), to_find, ft_strlen(to_find)))
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("our  %s\n",ft_strnstr("for test strnstr", " te", 6));
	printf("our  %s\n",ft_strnstr("fo", "", 6));
	printf("our  %s\n",ft_strnstr("for test strnstr", " te", 2));
	printf("our  %s\n",ft_strnstr("for test strnstr", "home", 10));
	printf("our  %s\n",ft_strnstr("for test strnstrs", "trs", 20));
	printf("our  %s\n",ft_strnstr("for test strnstr", "t s", 10));
	printf("our  %s\n",ft_strnstr("for tesa test rn", "test", 20));
	return (0);
}*/

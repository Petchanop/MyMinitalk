/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:50:52 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/21 13:32:28 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char const *str);

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t		n;
	size_t		nd;
	char		*pdst;
	char const	*psrc;

	pdst = dst;
	psrc = src;
	nd = 0;
	n = size;
	while (*(pdst + nd) && n--)
		nd++;
	n = size - nd;
	pdst = pdst + nd;
	if (n == 0)
		return (nd + ft_strlen(src));
	while (n != 1 && *psrc)
	{
		*pdst++ = *psrc;
		n--;
		psrc++;
	}
	*pdst = '\0';
	return (nd + ft_strlen(src));
}
/*
#include <bsd/string.h>

int	main(void)
{
	char	dst[23] = "test strlcat";
	char	ftdst[23] = "test strlcat";
	char const *src = "for cat";
	char const *ftsrc = "for cat";
	char const *sr1 = "for longer dest";
	char const *ftsr1 = "for longer dest";
	printf("strlcat      :  %d\ndst  : %s\n", strlcat(dst , src, 20), dst);
	printf("ft_strlcat   :  %d\ndst  : %s\n", ft_strlcat(ftdst , ftsrc, 20), ftdst);
	printf("strlcat      :  %d\ndst  : %s\n", strlcat(dst , sr1, 20), dst);
	printf("ft_strlcat   :  %d\ndst  : %s\n", ft_strlcat(ftdst , ftsr1, 20), ftdst);
	return (0);
}*/

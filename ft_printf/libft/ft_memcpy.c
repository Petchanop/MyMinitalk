/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 23:32:26 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/21 19:35:56 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*psrc;
	unsigned char	*pdst;

	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	if (!dst)
		return (NULL);
	while (len-- && psrc)
		*pdst++ = *psrc++;
	return (dst);
}
/*
int	main(void)
{
	const char	*src = "";
	char	dst[100] = "test";
	ft_memcpy(dst, src, 0);
	printf("memcpy : %s\n", dst);
	return (0);
}*/

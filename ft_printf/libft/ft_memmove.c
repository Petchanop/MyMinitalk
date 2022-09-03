/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:10:35 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/20 17:39:24 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t len);

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	char		*pdst;
	char const	*psrc;

	pdst = dst;
	psrc = src;
	if (!dst)
		return (NULL);
	if ((unsigned long)pdst < (unsigned long)psrc)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (len--)
			*(pdst + len) = *(psrc + len);
	}
	return (dst);
}
/*
int	main(void)
{
	char	dst[15] = "test memmove";
	char	dsm[15] = "test memmove";
	char	dmc[15] = "test memmove";
	char 	*src = dst;
	char 	*sr2 = dsm;
	char	*sr3 = dmc;
//	char const	*sr4 = "last";
	ft_memmove((src + 5), (sr3), 10);
	printf("ft_memmove : %s\n", (dmc));
	memcpy((src + 5), (src), 10);
	printf("memcpy     : %s\n", (dsm));
	memmove((sr2 + 5), (src), 10);
	printf("memmove    : %s\n", (dsm));
	ft_memmove(dst, sr2, 16);
	printf("dst : %s\n", dst);
	memmove(dsm , sr2, 16);
	printf("dsm : %s\n", dsm);
	ft_memmove(dst, sr3, 12);
	printf("dst : %s\n", dst);
	memmove(dsm , sr3, 12);
	printf("dsm : %s\n", dsm);
	ft_memmove(dst, sr4, 4);
	printf("dst : %s\n", dst);
	memmove(dsm , sr4, 4);
	printf("dsm : %s\n", dsm);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:35:57 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/21 15:41:27 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	ft_bzero(void *b, size_t len);

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	if (n == 0 || size == 0)
	{
		n = 1;
		size = 1;
	}
	ptr = (void *)malloc(n * size);
	if (!(ptr))
		return (NULL);
	ft_bzero(ptr, n * size);
	return (ptr);
}

/*
int	main(void)
{
	char	*call;
	char	*ft;

	call = calloc(1, 0);
	ft = ft_calloc(1, 0);
	printf("%d\n", sizeof(ft) == sizeof(call));
	printf("%d\n", (char *)ft == (char *)call);
	printf("ft : %s\ncl : %s\n", ft, call);
	return (0);
}*/

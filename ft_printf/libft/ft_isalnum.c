/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 23:48:19 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/21 02:19:13 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c);

int	ft_isalpha(int c);

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}
/*
#include <ctype.h>

int	main(void)
{
	printf("isalnum		: %d\n",isalnum('1'));
	printf("ft_isalnum	: %d\n",ft_isalnum('1'));
	printf("isalnum		: %d\n",isalnum('b'));
	printf("ft_isalnum	: %d\n",ft_isalnum('b'));
	printf("isalnum		: %d\n",isalnum('-'));
	printf("ft_isalnum	: %d\n",ft_isalnum('-'));
	printf("isalnum		: %d\n",isalnum('@'));
	printf("ft_isalnum	: %d\n",ft_isalnum('@'));
	printf("isalnum		: %d\n",isalnum(' '));
	printf("ft_isalnum	: %d\n",ft_isalnum(' '));
	printf("isalnum		: %d\n",isalnum('#'));
	printf("ft_isalnum	: %d\n",ft_isalnum('#'));
	printf("isalnum		: %d\n",isalnum('{'));
	printf("ft_isalnum	: %d\n",ft_isalnum('{'));
	printf("isalnum		: %d\n",isalnum('='));
	printf("ft_isalnum	: %d\n",ft_isalnum('='));
	return (0);
}*/

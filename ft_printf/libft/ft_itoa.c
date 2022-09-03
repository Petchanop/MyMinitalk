/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:30:30 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/28 23:43:14 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_finddigit(long long n)
{
	int	j;

	j = 0;
	if (n < 0)
		j = 1;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		j++;
	}
	return (j);
}

char	*ft_convert_neg(long long n, int digit, char *str)
{
	str[0] = '-';
	while (digit > 1)
	{
		str[digit - 1] = '0' - (n % 10);
		n /= 10;
		digit--;
	}
	return (str);
}

char	*ft_convert(long long n, int digit, char *str)
{
	while (digit)
	{
		str[digit - 1] = (n % 10) + '0';
		n /= 10;
		digit--;
	}
	return (str);
}

char	*ft_itoa(long long n)
{
	long long	num;
	int			j;
	char		*str;

	num = n;
	j = ft_finddigit(n);
	str = malloc((j + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	str[j] = '\0';
	if (num >= 0)
		str = ft_convert(num, j, str);
	else
		str = ft_convert_neg(num, j, str);
	return (str);
}
/*
#include <string.h>

int	main(void)
{
	printf("%s\n",ft_itoa(-2147483648));
	printf("%s\n",ft_itoa(-1000235));
	printf("%s\n",ft_itoa(-14586));
	printf("%s\n",ft_itoa(-1010));
	printf("%s\n",ft_itoa(-1));
	printf("%s\n",ft_itoa(0));
	printf("%s\n",ft_itoa(10));
	printf("%s\n",ft_itoa(1010));
	printf("%s\n",ft_itoa(1005000));
	printf("%s\n",ft_itoa(2147483647));
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:41:08 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/20 17:19:47 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char const *str);

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned long int	i;

	i = 0;
	while (*s)
	{
		f(i, s);
		i++;
		s++;
	}
}
/*
void
iter(unsigned int i, char * s) {
        *s += i;
}


void	iter(unsigned int index, char *c)
{
	if (*(c + index) >= 'a' && *(c + index) <= 'z')
		*(c + index) = *(c + index) - 32;
	else if (*(c + index) >= 'A' && *(c + index) <= 'Z')
		*(c + index) = *(c + index) + 32;
}

#include<string.h>

int	main(void)
{
	char	*str;

	str = malloc(sizeof(*str) * 12);

	strcpy(str, "LoReM iPsUm");
 
	ft_striteri(str, &iter);
	printf("%s\n", str);
}

int	main(void)
{
	char s[] = "0000000000";
        ft_striteri(s, iter);
	printf("%s\n", s);
        3  //(!strcmp(s, "0123456789"));
}*/

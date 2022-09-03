/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:10:49 by npiya-is          #+#    #+#             */
/*   Updated: 2022/03/28 00:31:10 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ctoa(char ch);

void	ft_putchar(char c);

char	*ft_hextoa(unsigned long long n, int up_or_lo);

char	*ft_utoa(unsigned int n);

size_t	ft_print_plus_or_space(char *str, t_format *form)
{
	char	c;

	if (form->flag == '+')
		c = '+';
	if (form->flag == ' ')
		c = ' ';
	if (*str != ' ' && form->type != 's')
	{
		ft_putchar(c);
		return (1);
	}
	if (!*str && form->width)
	{
		ft_putchar(c);
		return (1);
	}
	return (0);
}

size_t	ft_print_minus(size_t index, t_format *form)
{
	size_t	j;

	j = 0;
	if (form->width < 0)
		form->width *= -1;
	if (form->flag == '-')
	{
		while (form->width > (int)index)
		{
			ft_putchar(' ');
			form->width--;
			j++;
		}
	}
	return (j);
}

char	*ft_printf_char(t_format *form, va_list src)
{
	char	*str;
	char	c;

	if (form->type == 'c')
	{
		c = va_arg(src, int);
		return (ft_ctoa(c));
	}
	if (form->type == 's')
	{
		str = va_arg(src, char *);
		if (!str)
			str = "(null)";
		return (ft_strdup(str));
	}
	if (form->type == '%')
		return (ft_ctoa('%'));
	return (NULL);
}

char	*ft_printf_integer(t_format *form, va_list src)
{
	long int	i;

	i = 0;
	if (form->type == 'd')
	{
		i = va_arg(src, int);
		return (ft_itoa(i));
	}
	if (form->type == 'i')
	{
		i = va_arg(src, int);
		return (ft_itoa(i));
	}
	return (NULL);
}

char	*ft_printf_hex(t_format *form, va_list src)
{
	long int	u;

	u = 0;
	if (form->type == 'x')
	{
		u = va_arg(src, unsigned int);
		return (ft_hextoa(u, 1));
	}
	if (form->type == 'X')
	{
		u = va_arg(src, unsigned int);
		return (ft_hextoa(u, 0));
	}
	if (form->type == 'u')
	{
		u = va_arg(src, unsigned int);
		return (ft_utoa(u));
	}
	return (NULL);
}

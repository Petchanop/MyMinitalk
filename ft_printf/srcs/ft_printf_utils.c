/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:02:46 by npiya-is          #+#    #+#             */
/*   Updated: 2022/03/28 00:41:07 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ctoa(char ch);

char	*ft_ptoa(unsigned long long n);

char	*ft_printf_char(t_format *form, va_list src);

char	*ft_printf_integer(t_format *form, va_list src);

char	*ft_printf_hex(t_format *form, va_list src);

size_t	ft_printf_para(char *str, char ch, t_format *form);

size_t	ft_printf_sign(char *str, t_format *form);

size_t	ft_printf_bypara(char *str, t_format *form);

size_t	ft_printf_pre(char *str, t_format *form);

void	ft_putchar(char c);

size_t	ft_print_plus_or_space(char *str, t_format *form);

size_t	ft_print_minus(size_t index, t_format *form);

size_t	ft_putstr(char *str, size_t index, t_format *form);

size_t	ft_printf_hash(t_format *form)
{
	char	*hex;
	char	*x;
	char	*hash;

	hex = "0X";
	x = "0x";
	hash = NULL;
	if (form->flag == '#')
	{
		if (form->type == 'x')
			hash = x;
		if (form->type == 'X')
			hash = hex;
	}
	if (hash)
	{
		while (*hash)
			ft_putchar(*hash++);
		return (2);
	}
	return (0);
}

size_t	ft_putformatstr(char *str, t_format *form)
{
	size_t	i;
	size_t	len;
	char	ch;

	i = 0;
	len = 0;
	ch = 0;
	if (form->flag == '0' || form->pre)
		ch = '0';
	if ((form->flag == '+' || form->flag == ' ') && *str != '-')
		len = ft_print_plus_or_space(str, form);
	if (form->para || form->width)
	{
		len += ft_printf_pre(str, form);
		i += ft_printf_sign(str, form);
		len += ft_printf_para(str, ch, form);
	}
	if (form->type == 's' && form->pre == 1)
		return (len + ft_printf_bypara(str, form));
	if (*str != '0' && form->flag == '#')
		len += ft_printf_hash(form);
	i += ft_putstr(str, i, form);
	i += ft_print_minus(i + len, form);
	return (len + i);
}

char	*ft_convert_hex(long long n, int digit, char *str, int up_or_lo)
{
	char	*hex;
	char	*lower;
	char	*upper;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	if (n == 0)
		str[0] = '0';
	if (up_or_lo)
		hex = lower;
	else
		hex = upper;
	while (digit)
	{
		str[digit - 1] = hex[(n % 16)];
		n /= 16;
		digit--;
	}
	return (str);
}

char	*ft_hextoa(unsigned long long n, int up_or_lo)
{
	unsigned long long	i;
	int					j;
	char				*str;

	i = n / 16;
	j = 1;
	while (i)
	{
		i /= 16;
		j++;
	}
	if (n < 0)
		j += 1;
	str = malloc((j + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n >= 0)
		str = ft_convert_hex(n, j, str, up_or_lo);
	else
	{
		str = ft_convert_hex(n, j, str, up_or_lo);
		str[0] = '-';
	}
	str[j] = 0;
	return (str);
}

char	*ft_convert_args(t_format *form, va_list src)
{
	unsigned char	*ptr;
	long int		u;

	u = 0;
	if (form->type == 'c' || form->type == 's' || form->type == '%')
		return (ft_printf_char(form, src));
	if (form->type == 'd' || form->type == 'i')
		return (ft_printf_integer(form, src));
	if (form->type == 'x' || form->type == 'X' || form->type == 'u')
		return (ft_printf_hex(form, src));
	if (form->type == 'p')
	{
		ptr = (unsigned char *)va_arg(src, void *);
		return (ft_ptoa((unsigned long long)ptr));
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("%s\n", ft_hextoa(26, 0));
	printf("%s\n", ft_hextoa(321, 0));
	printf("%s\n", ft_hextoa(1234, 1));
	printf("%s\n", ft_hextoa(12345, 0));
	printf("%s\n", ft_hextoa(789653, 1));
	printf("%s\n", ft_hextoa(6725624, 0));
	printf("%s\n", ft_hextoa(82938725, 1));
}*/

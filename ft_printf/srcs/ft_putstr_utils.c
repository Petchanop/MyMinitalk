/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:43:42 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/04 13:37:30 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_data(t_format	*format);

size_t	ft_print_minus(size_t index, t_format *form);

void	ft_putchar(char c);

size_t	ft_printf_sign(char *str, t_format *form)
{
	size_t	i;

	i = 0;
	if (*str == '-' && form->type != 's')
	{
		if (form->pre)
			form->para += 1;
		ft_putchar(*str);
		i++;
	}
	return (i);
}

size_t	ft_putstr(char *str, size_t index, t_format *form)
{
	size_t	i;

	i = 0;
	if (form->width < 0)
		form->width *= -1;
	if (form->width > form->para && *str == '0' && form->pre && form->para == 0)
		return (i);
	if (*str == '0' && form->pre && !form->para && !form->width)
		return (i);
	if (form->type == 'c' && *str == '\0')
	{
		ft_putchar('\0');
		return (++i);
	}
	while (*(str + index))
	{
		ft_putchar(*(str + index));
		index++;
		i++;
	}
	return (i);
}

size_t	ft_printf_pre(char *str, t_format *form)
{
	size_t	i;
	int		para;

	i = 0;
	para = 0;
	if (form->flag != '-')
	{
		if ((form->type == 'c' && *str == '\0')
			|| (*str == '-' && form->para > (int)ft_strlen(str)))
			para++;
		if (form->para > (int)ft_strlen(str))
			para += form->para;
		else if (*str != '0' || (*str == '0' && form->width
				&& (!form->flag || form->type == 'p')))
			para += (int)ft_strlen(str);
		else if (*str == '0' && form->para)
			para += 1;
		while (form->width - (int)i > para)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (i);
}

size_t	ft_printf_para(char *str, char ch, t_format *form)
{
	size_t	len;

	len = 0;
	if (!ch)
		return (len);
	if (form->type != 's' && form->para)
	{
		while (form->para - (int)len > (int)ft_strlen(str))
		{
			ft_putchar(ch);
			len++;
		}
	}
	return (len);
}

size_t	ft_printf_bypara(char *str, t_format *form)
{
	size_t	i;

	i = 0;
	while (form->para && *(str + i))
	{
		ft_putchar(*(str + i));
		form->para--;
		i++;
	}
	i += ft_print_minus(i, form);
	return (i);
}

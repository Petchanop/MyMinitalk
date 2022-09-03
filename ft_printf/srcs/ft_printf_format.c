/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:44:04 by npiya-is          #+#    #+#             */
/*   Updated: 2022/03/28 00:24:57 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_count_printf(t_format *form, va_list src);

t_format	*ft_check_type(char *format, t_format *form);

int			ft_check_format(const char c);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_print_format(const char *format, t_format *form, va_list src)
{
	size_t		i;
	int			count;
	t_format	*tmp;

	i = 0;
	count = 0;
	while (*(format + i) && i < ft_strlen(format))
	{
		if (ft_check_format(*(format + i)) && form)
		{
			count += ft_count_printf(form, src);
			i = form->n + form->len;
			tmp = form;
			form = form->next;
			free(tmp);
		}
		if (!ft_check_format(*(format + i)) && *(format + i))
		{
			count++;
			ft_putchar(*(format + i));
			i++;
		}
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:05:52 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/04 13:28:21 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_args(t_format *form, va_list src);

size_t	ft_putformatstr(char *str, t_format *form);

size_t	ft_count_printf(t_format *form, va_list src)
{
	char	*str;
	size_t	count;

	count = 0;
	str = ft_convert_args(form, src);
	if (str)
		count += ft_putformatstr(str, form);
	free(str);
	return (count);
}
/*
void    ft_print_data(t_format  *format)
{
	while (format)
	{
		printf("form_data->n   : %d\n", format->n);
        printf("form_data->len : %d\n", format->len);
        printf("form_data->p   : %d\n", format->para);
        printf("form_data->w   : %d\n", format->width);
        printf("form_data->pr  : %d\n", format->pre);
        printf("form_data->f   : %c\n", format->flag);
        printf("form_data->t   : %c\n", format->type);
        format = format->next;
    }
}*/

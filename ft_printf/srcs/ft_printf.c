/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:57:56 by npiya-is          #+#    #+#             */
/*   Updated: 2022/03/28 00:18:06 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_check_type(char *format, t_format *form);

int			ft_print_format(const char *format, t_format *form, va_list src);

int			ft_check_format(const char c);

size_t		ft_putstr(char *str, t_format *form);

char		*ft_convert_args(t_format *form, va_list src);

void		ft_putchar(char c);

void		ft_print_data(t_format	*format);

size_t	ft_count_sign(t_format *format)
{
	t_format	*tmp;
	size_t		i;

	tmp = format;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_addformat(t_format **form_data, t_format *form)
{
	t_format	*temp;

	if (*form_data)
	{
		temp = *form_data;
		while (temp->next)
			temp = temp->next;
		temp->next = form;
		form_data = &temp;
	}
	else
		*form_data = form;
}

void	ft_newformat(t_format *new)
{
	new->n = 0;
	new->len = 0;
	new->para = 0;
	new->width = 0;
	new->pre = 0;
	new->flag = 0;
	new->type = 0;
	new->next = 0;
}

t_format	*ft_create_format(const char *format)
{
	static t_format	*form;
	static t_format	*form_data;
	char			*ptr;
	int				i;

	i = 0;
	ptr = (char *)format;
	form_data = NULL;
	while (*(ptr + i))
	{
		if (ft_check_format(*(ptr + i)))
		{
			i++;
			form = malloc(sizeof(t_format));
			ft_newformat(form);
			ft_check_type((ptr + i), form);
			form->n = i;
			ft_addformat(&form_data, form);
		}
		i++;
	}
	return (form_data);
}

int	ft_printf(const char *format, ...)
{
	va_list		src;
	int			max;
	t_format	*form;

	max = 0;
	form = ft_create_format(format);
	va_start(src, format);
	max = ft_print_format(format, form, src);
	va_end(src);
	return (max);
}
/*//ft_print_data(form_data);
int	main(void)
{
	 char *s2 = "Mussum Ipsum, 
	 cacilds vidis litro abertis. Posuere libero varius. 
	 Nullam a nisl ut ante blandit hendrerit. Aenean sit 
	 amet nisi. Atirei o pau no gatis, per gatis num morreus.";
	 ft_printf("%s", "");
	 ft_printf(" %s", "");
	 ft_printf("%s ", "");
	 ft_printf(" %s ", "");
	 ft_printf(" %s ", "-");
	 ft_printf(" %s %s ", "", "-");
	 ft_printf(" %s %s ", " - ", "");
	 ft_printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
	 ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	// ft_printf(" NULL %s NULL ", NULL);
	// printf("\n %s %s %s %s %s\n", " - ", "", "4", "", s2);
}*/

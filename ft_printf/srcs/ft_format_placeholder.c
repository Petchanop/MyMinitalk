/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_placeholder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:13:34 by npiya-is          #+#    #+#             */
/*   Updated: 2022/03/27 22:21:08 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_precision(const char c)
{
	if (c == '.')
		return (1);
	return (0);
}

int	ft_check_widthf(const char c)
{
	if (c == '*')
		return (1);
	return (0);
}

int	ft_flags_format(const char c)
{
	if (c == '+')
		return (1);
	if (c == '#')
		return (2);
	if (c == ' ')
		return (3);
	if (c == '0')
		return (4);
	if (c == '-')
		return (4);
	return (0);
}

int	ft_check_para(const char c, const char dsign)
{
	if (ft_isdigit(c) && dsign == '$')
		return (1);
	return (0);
}

int	ft_check_format(const char c)
{
	if (c == '%')
		return (1);
	return (0);
}

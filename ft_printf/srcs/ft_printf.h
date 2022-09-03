/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:58:18 by npiya-is          #+#    #+#             */
/*   Updated: 2022/04/28 21:46:16 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_format
{
	int				n;
	int				len;
	int				para;
	int				width;
	int				pre;
	char			flag;
	char			type;
	struct s_format	*next;
}	t_format;

int	ft_printf(const char *format, ...);
int	ft_print_format(const char *format, t_format *form, va_list src);
#endif

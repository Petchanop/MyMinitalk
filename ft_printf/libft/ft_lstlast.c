/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:08:07 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/19 17:47:03 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst)
{
	int	i;

	if (!lst)
		return (lst);
	i = ft_lstsize(lst) - 1;
	while (i)
	{
		lst = lst->next;
		i--;
	}
	return (lst);
}

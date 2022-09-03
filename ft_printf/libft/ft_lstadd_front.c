/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:01:11 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/19 17:46:04 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	**lst;
	t_list	*new;
	t_list	*s1;
	t_list	*s2;
//	t_list	*s3;

	new = ft_lstnew("test1");
	s1 = ft_lstnew("add1");
	s2 = ft_lstnew("add2");
	lst = &new;	
//	ft_lstadd_front(lst, new);
	ft_lstadd_front(lst, s1);
	ft_lstadd_front(lst, s2);
	printf("lst : %s\n", (char *)(*lst)->content);
	printf("lst->next : %s\n", (char *)((*lst)->next)->content);
	printf("lstsize : %d\n", ft_lstsize(*lst));
	return (0);
}*/

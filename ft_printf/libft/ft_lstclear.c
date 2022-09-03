/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:50:39 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/19 17:46:22 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*de;

	de = *lst;
	while (*lst)
	{
		del((*lst)->content);
		*lst = (*lst)->next;
		free(de);
		de = *lst;
	}
}
/*

int	main(void)
{
	t_list	*test;
	t_list	*t1 = ft_lstnew("test1");
	t_list	*t2 = ft_lstnew("test2");
	t_list	*t3 = ft_lstnew("test3");
	
	test = NULL;
	printf("test : %p\n", test);
	ft_lstadd_front(&test,t1);
	ft_lstadd_front(&test,t2);
	ft_lstadd_front(&test,t3);
	ft_lstclear(&test, del);
}

void	del(void *content)
{
	while (*(char *)content)
		content++;
}*/

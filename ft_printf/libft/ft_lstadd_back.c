/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:21:51 by npiya-is          #+#    #+#             */
/*   Updated: 2022/02/19 17:45:51 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content);

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst)
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		lst = &temp;
	}
	else
		*lst = new;
}
/*
int	main(void)
{
	t_list	*test;
	t_list	*t1 = ft_lstnew("test1");
	t_list	*t2 = ft_lstnew("test2");
	t_list	*t3 = ft_lstnew("test3");

	test = NULL;
	ft_lstadd_back(&test, t1);
	ft_lstadd_back(&test, t2);
	ft_lstadd_back(&test, t3);
	while (test)
	{
		printf("test :  %s\n", (char *)test->content);
		test = test->next;
	}
}*/

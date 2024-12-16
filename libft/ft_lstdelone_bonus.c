/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:45:57 by aakouhar          #+#    #+#             */
/*   Updated: 2023/11/22 21:13:22 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
#include <stdio.h>
#include <stdlib.h>

void	delet(void *lst)
{
	free(lst);
}
int	main(void)
{
	t_list *node0;
	t_list *node1;
	t_list *node2;
	t_list **ptr;

	ptr = &node0;
	node0 = ft_lstnew((void *)10);
	node1 = ft_lstnew((void *)20);
	node2 = ft_lstnew((void *)30);
	node0->next = node1;
	node1->next = node2;
	node2->next = NULL;
	while (ptr)
	{
		printf("%i\n", *((int *)ptr->content));
		ptr = ptr->next;
	}
	ft_lstdelone(ptr, delet);
	printf("%i\n", ((int)node1->next));
}*/

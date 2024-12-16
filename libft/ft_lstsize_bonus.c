/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:46:01 by aakouhar          #+#    #+#             */
/*   Updated: 2023/11/22 17:55:49 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/* #include <stdio.h>
int	main(void)
{
	t_list *lst;
	t_list *lst2 = NULL;
	t_list *lst3;
	lst2 = ft_lstnew("ali");
	lst3 = ft_lstnew("tiima");
	lst2->next = lst3;
	lst3->next = NULL;
	lst = lst2;
	printf("%i\n", ft_lstsize(lst));
} */
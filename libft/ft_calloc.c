/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:48:05 by aakouhar          #+#    #+#             */
/*   Updated: 2023/11/22 15:39:26 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t c, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(size * c);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (size * c));
	return (ptr);
}
/* #include <stdio.h>

int	main(void)
{
	int *ptr = ft_calloc(4 , sizeof(int));
	int i = 0;
	while (i < 4)
	{
		printf("%i\n", ptr[i]);
		i++;
	}
} */

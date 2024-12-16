/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:15:17 by aakouhar          #+#    #+#             */
/*   Updated: 2023/11/22 20:30:24 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int n, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)s)[i] = (unsigned char)n;
		i++;
	}
	return (s);
}
/* #include <stdio.h>
int	main(void)
{
	int arr[] = {0,0};

	int	*ptr;
	ptr = (int *)ft_memset(&arr[0], 128, 4);
	ptr = (int *)ft_memset(&arr[0], 255, 3);
	printf("%d\n", ptr[0]);
	printf("%d\n", ptr[1]);


} */

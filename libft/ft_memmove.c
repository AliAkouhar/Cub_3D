/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:33:49 by aakouhar          #+#    #+#             */
/*   Updated: 2023/11/22 15:50:30 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return ((void *)src);
	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (dest > src)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
/* #include <string.h>
#include <stdio.h>

int	main(void) {
	char str[] = "abcde";
	printf("%s\n", ft_memmove(str + 2 , str, 3));
	printf("%s\n", memmove(str + 2, str, 3));
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:28:54 by aakouhar          #+#    #+#             */
/*   Updated: 2023/11/22 20:52:10 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	src_size;
	size_t	i;
	size_t	j;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	j = dest_size;
	i = 0;
	if (size == 0 || dest_size >= size)
		return (size + src_size);
	while (src[i] && i < size - dest_size - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest_size + src_size);
}
/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char *src = " world";
	char *dest = NULL;
	// size_t i = ft_strlcat(dest, src, 20);
	// printf("%s %lu", dest, i);
	printf("%lu ", strlcat(dest, src, 12));
	printf("%s", dest);
} */
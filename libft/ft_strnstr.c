/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:09:25 by aakouhar          #+#    #+#             */
/*   Updated: 2023/11/22 17:19:24 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	length;

	length = ft_strlen(to_find);
	if (to_find[0] == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] && len >= (length + i))
	{
		if (ft_strncmp((str + i), to_find, length) == 0)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
/* #include <stdio.h>
#include <string.h>

int	main(void)

{
	char *s2 = "not";
	// char *i1 = strnstr("uguhuhuih", NULL, 30);
	// printf("%s\n", i1);
	char *i2 = ft_strnstr("jhghjgugg", NULL, 30);
	printf("%s\n", i2);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:59:24 by aakouhar          #+#    #+#             */
/*   Updated: 2023/11/22 17:31:11 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	i = 0;
	end = ft_strlen(s1) - 1;
	while (check(s1[start], set) && s1[start])
		start++;
	if (!s1[start])
		return (ft_strdup(""));
	while (check(s1[end], set))
		end--;
	str = (char *)malloc((end - start + 2) * sizeof(char));
	if (!str)
		return (NULL);
	while (start <= end && s1[start])
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}

/* #include <stdio.h>
int	main(void)
{
	char *str;
	str = ft_strtrim("ggggheogheoggggffoeoggg", "");
	printf("%s\n", str);
} */
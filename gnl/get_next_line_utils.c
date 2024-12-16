/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:33:28 by fbazaz            #+#    #+#             */
/*   Updated: 2024/09/09 10:39:18 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen2(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup2(char *str)
{
	size_t	size;
	int		i;
	char	*ptr;

	size = ft_strlen2(str);
	i = 0;
	ptr = malloc((size + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	int		i;
	size_t	len1;
	char	*newstring;

	if (!s1)
		return (ft_strdup2(s2));
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen2(s1);
	newstring = malloc((len1 + ft_strlen2(s2) + 1) * sizeof(char));
	if (!newstring)
		return (NULL);
	i = -1;
	while (s1[++i])
		newstring[i] = s1[i];
	i = -1;
	while (s2[++i])
	{
		newstring[len1] = s2[i];
		len1++;
	}
	newstring[len1] = '\0';
	return (free(s1), newstring);
}

int	ft_strchr2(char *s, int c)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen2(s);
	str = (char *)s;
	while (i <= len)
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

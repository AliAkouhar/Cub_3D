/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 09:54:29 by aakouhar          #+#    #+#             */
/*   Updated: 2023/11/23 14:47:31 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_strncpy(char *dest, char const *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_fill(char **arr, char const *s, char c, int num)
{
	int	count;
	int	index;
	int	j;

	count = 0;
	j = 0;
	while (s[count] && j < num)
	{
		while (s[count] == c)
			count++;
		index = count;
		while (s[count] != c && s[count])
			count++;
		arr[j] = (char *)malloc(sizeof(char) * (count - index + 1));
		if (!arr[j])
			return (0);
		ft_strncpy(arr[j], &s[index], (count - index));
		j++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		count_wrds;
	char	**arr;
	int		checker;
	char	**ptr;

	if (!s)
		return (NULL);
	count_wrds = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (count_wrds + 1));
	if (!arr)
		return (NULL);
	arr[count_wrds] = NULL;
	checker = ft_fill(arr, s, c, count_wrds);
	if (checker == 0)
	{
		ptr = ft_free(arr);
		return (ptr);
	}
	return (arr);
}

/* #include <stdio.h>

 int	main(void)
{
	// char *str = "This is a test string";
	char **words = ft_split("hello!", ' ');

	for (int i = 0; words[i] != NULL; i++)
	{
		printf("%s\n", words[i]);
	}


	return (0);
}  */

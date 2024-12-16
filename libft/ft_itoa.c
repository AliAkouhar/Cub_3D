/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:49:38 by aakouhar          #+#    #+#             */
/*   Updated: 2023/11/25 09:32:32 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count = 1;
		n = -n;
	}
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	ft_fill(char *str, long nb, int count)
{
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		str[count] = nb % 10 + '0';
		nb /= 10;
		count--;
	}
}

char	*ft_itoa(int n)
{
	int		count;
	char	*str;
	long	nb;

	nb = (long)n;
	count = ft_count(n);
	str = malloc(count + 1);
	if (!str)
		return (NULL);
	str[count] = '\0';
	ft_fill(str, nb, (count - 1));
	return (str);
}

/* #include <stdio.h>
#include <limits.h>
int main()
{
	printf("%s\n", ft_itoa(INT_MAX));
	printf("%s\n", ft_itoa(INT_MIN));
	printf("%s\n", ft_itoa(-1234));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(858947));
} */

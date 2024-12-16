/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:52:11 by fbazaz            #+#    #+#             */
/*   Updated: 2024/09/09 10:39:33 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *str)
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (free(str), NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buffer), free(str), NULL);
		buffer[read_bytes] = '\0';
		str = ft_strjoin2(str, buffer);
		if (ft_strchr2(str, '\n'))
			break ;
	}
	return (free(buffer), str);
}

char	*ft_fill(char *str)
{
	char	*p;
	int		i;

	i = 0;
	p = NULL;
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	p = (char *)malloc(sizeof(char) * (i + 2));
	if (!p)
		return (free(str), NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		p[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_new_str(char *str)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	p = NULL;
	if (!str || str[0] == '\0')
		return (free(str), NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	p = (char *)malloc(sizeof(char) * (ft_strlen2(str) - i + 1));
	if (!p)
		return (free(str), NULL);
	i++;
	j = 0;
	while (str[i])
		p[j++] = str[i++];
	p[j] = '\0';
	return (free(str), p);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_line(fd, str);
	if (!str)
		return (NULL);
	line = ft_fill(str);
	str = ft_new_str(str);
	return (line);
}

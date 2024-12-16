/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:52:14 by fbazaz            #+#    #+#             */
/*   Updated: 2024/09/09 10:39:49 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_new_str(char *str);
char	*ft_fill(char *str);
char	*ft_read_line(int fd, char *str);
// utils
char	*ft_strjoin2(char *s1, char *s2);
size_t	ft_strlen2(char *s);
int		ft_strchr2(char *s, int c);
char	*ft_strdup2(char *str);

#endif

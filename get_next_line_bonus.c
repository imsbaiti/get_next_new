/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imsbaiti <imsbaiti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 01:33:04 by imsbaiti          #+#    #+#             */
/*   Updated: 2024/12/31 20:03:34 by imsbaiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_next_line(char *str)
{
	char	*rest;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (str[i] == '\0')
		return (free(str), NULL);
	rest = malloc(ft_strlen(str) - i + 1);
	if (!rest)
		return (free(str), NULL);
	j = 0;
	while (str[i])
		rest[j++] = str[i++];
	rest[j] = '\0';
	free(str);
	return (rest);
}

char	*ft_line(char *str)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str || !(*str))
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	while (j < i)
	{
		res[j] = str[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_read(char *str, int fd)
{
	char	*buffer;
	int		bytes;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(str);
		return (NULL);
	}
	bytes = 1;
	while (bytes > 0 && ft_strchr(str, '\n') == -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(str), NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (free(buffer), NULL);
	}
	return (free(buffer), str);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	str[fd] = ft_read(str[fd], fd);
	if (!str[fd])
		return (NULL);
	result = ft_line(str[fd]);
	if (!result)
		return (free(str[fd]), str[fd] = NULL, NULL);
	str[fd] = ft_next_line(str[fd]);
	return (result);
}

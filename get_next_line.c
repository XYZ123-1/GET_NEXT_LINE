/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrabenah <jrabenah@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 07:40:08 by jrabenah          #+#    #+#             */
/*   Updated: 2025/03/27 12:00:54 by jrabenah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static char	*ft_extract_line_after_n(char *line_buffer)
{
	char	*tmp;
	size_t	i;

	if (!line_buffer)
		return (NULL);
	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0' || line_buffer[i + 1] == '\0')
		return (NULL);
	tmp = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (!tmp)
		return (NULL);
	if (tmp[0] == '\0')
	{
		free(tmp);
		tmp = NULL;
	}
	line_buffer[i + 1] = '\0';
	return (tmp);
}

static char	*ft_cloud_read(int fd, char *tmp, char *buffer)
{
	ssize_t	count_bytes;
	char	*temp;

	count_bytes = 1;
	while (count_bytes > 0)
	{
		count_bytes = read(fd, buffer, BUFFER_SIZE);
		if (count_bytes == -1)
			return (free(tmp), NULL);
		if (count_bytes == 0)
			break ;
		buffer[count_bytes] = '\0';
		temp = tmp;
		if (!temp)
			temp = ft_strdup("");
		tmp = ft_strjoin(temp, buffer);
		free(temp);
		if (!tmp)
			break ;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		*buffer;
	char		*newline_pos;
	char		*new_storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(storage), storage = NULL, NULL);
	line = ft_cloud_read(fd, storage, buffer);
	free(buffer);
	if (!line)
		return (free(storage), storage = NULL, NULL);
	newline_pos = ft_strchr(line, '\n');
	if (newline_pos)
	{
		new_storage = ft_extract_line_after_n(line);
		storage = new_storage;
		return (line);
	}
	storage = NULL;
	return (line);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*nptr;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	nptr = malloc(len + 1);
	if (!nptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		nptr[i] = s[i];
		i++;
	}
	nptr[len] = '\0';
	return (nptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p)
	{
		if ((c >= 256 && *p == c % 256) || (*p == c))
			return (p);
		p++;
	}
	if (*p == '\0' && *p == c)
		return (p);
	return (NULL);
}

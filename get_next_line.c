/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrabenah <jrabenah@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 07:40:08 by jrabenah          #+#    #+#             */
/*   Updated: 2025/03/21 15:50:03 by jrabenah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#define	BUFFER_SIZE 1024
#include <stdio.h>
#include <fcntl.h>


char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	tmp[BUFFER_SIZE];
	char		*buffer_line;
	ssize_t		count_bytes;
	size_t		i;

	count_bytes = 0;
	while (1)
	{
		i = 0;
		count_bytes = read(fd, buffer, 10);
		if (count_bytes == 0 || count_bytes == -1)
			return (NULL);
		if (count_bytes > 0)
		{
			buffer[count_bytes] = '\0';
			ft_strcat(tmp, buffer);
			while (tmp[i])
			{
				if (tmp[i] != '\n')
					i++;
				break;
			}
			if (tmp[i] == '\n')
			{
				buffer_line = malloc (sizeof * buffer_line * (i + 1));
				if (!buffer_line)
					return (NULL);
				buffer_line = ft_strncpy(buffer_line, tmp, i);
			}
		}
	}
	return (buffer_line);
}

int	main()
{
	int	c_read = open("test.txt", O_RDONLY);

	printf("%s",get_next_line(c_read));
}

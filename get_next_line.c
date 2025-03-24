/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrabenah <jrabenah@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 07:40:08 by jrabenah          #+#    #+#             */
/*   Updated: 2025/03/24 13:48:28 by jrabenah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#define	BUFFER_SIZE 1
#include <stdio.h>
#include <fcntl.h>

static char *extract_line_after_n(char *line_buffer)
{
    char    *tmp;
    ssize_t    i;
    
    i = 0;
    while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
        i++;
    if (line_buffer[i] == 0 || line_buffer[1] == 0)
        return (NULL);
    tmp = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
    if (*tmp == 0)
    {
        free(tmp);
        tmp = NULL;
    }  
    line_buffer[i + 1] = 0;
    return (tmp);
}

static char	*cloud_read(int fd, char *tmp, char *buffer)
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
			break;
		buffer[count_bytes] = '\0';
		if (!tmp)
			tmp = ft_strdup("");
		temp = tmp;
		tmp = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return (tmp);
}

char    *get_next_line(int fd)
{
    static char *tmp;
    char        *line;
    char        *newline;
    char        *buffer;
    char        *line_new;
    
    buffer = malloc((BUFFER_SIZE + 1) * sizeof * buffer);
    if (fd < 0 || (BUFFER_SIZE <= 0) || read(fd, 0, 0) < 0)
        return(free(tmp), tmp = NULL, NULL);
    if (!buffer)
        return (NULL);
    line = cloud_read(fd, tmp, buffer);
    free(buffer);
    buffer = NULL;
    if (!line)
        return (NULL);
    newline = ft_strchr(line, '\n');
    if (newline)
    {
        line_new = ft_substr(line, 0, newline - line + 1);
        newline = extract_line_after_n(line);
    }
    else
        line_new = ft_strdup(line);
    return (tmp = newline, line_new);
}

int	main()
{
	int	c_read = open("test.txt", O_RDONLY);

        printf("%s", get_next_line(c_read));
        printf("%s", get_next_line(c_read));
        printf("%s", get_next_line(c_read));
        printf("%s", get_next_line(c_read));
        printf("%s", get_next_line(c_read));
        printf("%s", get_next_line(c_read));
        printf("%s", get_next_line(c_read));
        printf("%s", get_next_line(c_read));
        printf("%s", get_next_line(c_read));


    

}
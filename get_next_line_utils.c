/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrabenah <jrabenah@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:10:52 by jrabenah          #+#    #+#             */
/*   Updated: 2025/03/25 13:51:06 by jrabenah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	const char	*p;

	p = str;
	while (*p)
	{
		p++;
	}
	return (p - str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = malloc((len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strncpy(char *dest, char const *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	*ft_memset(void *dest, int c, size_t size)
{
	char			*p;
	unsigned int	i;

	p = (char *)dest;
	i = 0;
	while (i < size)
	{
		p[i] = (char)c;
		i++;
	}
	return (p);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	src_len;
	char	*nptr;

	nptr = NULL;
	src_len = ft_strlen(s);
	if (!s || start < 0 || len < 0)
		return (NULL);
	if (start > src_len || len == 0)
	{
		nptr = malloc(sizeof * nptr * 1);
		if (!nptr)
			return (NULL);
		nptr[0] = '\0';
		return (nptr);
	}
	if (len > src_len - start)
		len = src_len - start;
	nptr = malloc(sizeof * nptr * (len + 1));
	if (!nptr)
		return (free(nptr), NULL);
	ft_memset(nptr, 0, (len + 1));
	ft_strncpy(nptr, s + start, len);
	return (nptr);
}

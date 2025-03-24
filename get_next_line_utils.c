/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrabenah <jrabenah@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:10:52 by jrabenah          #+#    #+#             */
/*   Updated: 2025/03/24 08:54:55 by jrabenah         ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	char	*nptr;
	int		len;
	int		i;

	len = ft_strlen(s);
	i = 0;
	nptr = malloc(sizeof * nptr * (len + 1));
	if (nptr == NULL)
		return (NULL);
	while (s[i])
	{
		nptr[i] = s[i];
		i++;
	}
	nptr[i] = '\0';
	return (nptr);
}

char	*ft_strcpy(char const *dest, char const *src)
{
	int		i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strcat(char const *dest, char const *src)
{
	int		i;
	int		j;
	char	*d;
	char	*s;

	j = 0;
	i = 0;
	d = (char *)dest;
	s = (char *)src;
	while (*(d + j))
	{
		j++;
	}
	while (*(s + i))
	{
		*(d + j) = *(s + i);
		j++;
		i++;
	}
	d[j] = '\0';
	return (d);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nptr;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	nptr = malloc(sizeof * nptr * (i + j + 1));
	if (!nptr)
		return (NULL);
	if (nptr)
	{
		ft_strcpy(nptr, s1);
		ft_strcat(nptr, s2);
	}
	return (nptr);
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

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	src_len;
	char	*nptr;

	src_len = ft_strlen(s);
	if (!s || start < 0 || len < 0)
	{
		return (NULL);
	}
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
		return (NULL);
	ft_strncpy(nptr, s + start, len);
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
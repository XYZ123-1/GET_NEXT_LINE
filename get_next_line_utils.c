/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrabenah <jrabenah@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:10:52 by jrabenah          #+#    #+#             */
/*   Updated: 2025/03/21 16:09:24 by jrabenah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, size_t n)
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
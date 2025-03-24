/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrabenah <jrabenah@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 07:36:37 by jrabenah          #+#    #+#             */
/*   Updated: 2025/03/24 08:56:42 by jrabenah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
char	*ft_strncpy(char *dest, char *src, size_t n);
char	*ft_strcpy(char const *dest, char const *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char const *dest, char const *src);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);

#endif
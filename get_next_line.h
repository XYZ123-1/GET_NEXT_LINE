/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrabenah <jrabenah@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 07:36:37 by jrabenah          #+#    #+#             */
/*   Updated: 2025/03/21 13:46:23 by jrabenah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
char	*ft_line_extraction(char *str);
char	*ft_strncpy(char *dest, char *src, size_t n);
char	*ft_strcpy(char const *dest, char const *src);
char	*ft_strcat(char const *dest, char const *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);

#endif
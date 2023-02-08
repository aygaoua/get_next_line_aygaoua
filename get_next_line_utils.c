/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:33:12 by azgaoua           #+#    #+#             */
/*   Updated: 2023/02/08 20:31:00 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s2) + ft_strlen(s1);
	s = malloc(len + 1);
	if (!s)
		return (0);
	i = 0;
	while (s1[i])
		i++;
	ft_memmove(s, s1, i);
	ft_memmove((s + i), s2, ft_strlen(s2));
	s[len] = '\0';
	return (s);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

    if(!str)
    {
        return (0);
    }
	i = 0;
	while (str[i] != '\0')
			i++;
	return (i);
}
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

    if(!dst || !src)
        return (0);
	d = (char *)dst;
	s = (char *)src;
	if (d == 0 && s == 0)
		return (0);
	if (s < d)
	{
		while (len--)
			d[len] = s[len];
	}
	else
		d = ft_memcpy(d, s, len);
	return (d);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	i = 0;
	if (!dst && !src)
		return (0);
	d = (char *)dst;
	s = (const char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

//     if(!s)
//         return (0);
// 	i = 0;
// 	while (0 == 0)
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *) s + i);
// 		if (s[i] == '\0')
// 			return (NULL);
// 		i++;
// 	}
// 	return (NULL);
// }
char    *ft_strchr(const char *s, int c)
{
    if(!s)
        return (0);
    while (*s != '\0')
    {
        if ((unsigned char)*s == (unsigned char)c)
            return ((char *)s);
        s++;
    }
    if (c == 0)
        return ((char *)s);
    return (0);
}

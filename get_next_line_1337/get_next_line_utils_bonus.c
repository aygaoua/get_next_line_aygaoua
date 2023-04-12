/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 02:32:44 by azgaoua           #+#    #+#             */
/*   Updated: 2023/03/08 02:36:20 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		len;
	char		*rtn;
	int			j;
	int			i;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (len != 0)
		rtn = ft_calloc(len + 1);
	else
		return (NULL);
	while (s1 != NULL && s1[i] != 0)
	{
		rtn[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j] != 0)
	{
		rtn[i] = s2[j];
		i++;
		j++;
	}
	return (rtn);
}

void	ft_bzero(void *s, size_t nbr)
{
	char	*str;
	size_t	i1;

	str = (char *)s;
	i1 = 0;
	while (i1 < nbr)
		str[i1++] = 0;
}

void	*ft_calloc(size_t count)
{
	char	*result;

	result = malloc(count);
	if (!result)
		return (NULL);
	ft_bzero(result, count);
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i2;
	size_t	j;
	char	*str;

	str = ft_calloc(len + 1);
	if (!str)
		return (NULL);
	i2 = 0;
	j = 0;
	while (s[i2])
	{
		if (i2 >= start && j < len)
		{
			str[j] = s[i2];
			j++;
		}
		i2++;
	}
	free (s);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:04:42 by azgaoua           #+#    #+#             */
/*   Updated: 2023/03/09 04:54:09 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*helper;
	int			sub;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	helper = rdwr_and_search(fd, helper);
	sub = ft_strlen(helper);
	if (sub && helper[sub - 1])
	{
		sub = -1;
		line = ft_calloc(ft_strlen(helper) + 1);
		while (helper[++sub] != '\n' && helper[sub] != '\0')
			line[sub] = helper[sub];
		if (ft_strchr(helper, '\n'))
		{
			helper = ft_substr(helper, sub + 1, ft_strlen(helper) - sub - 1);
			return (line[sub] = '\n', line);
		}
		else if (!ft_strchr(helper, '\n'))
			return (free(helper), helper = NULL, line);
	}
	return (line);
}

char	*rdwr_and_search(int fd, char *helper)
{
	int		nbr_chars;
	char	*tmp;

	nbr_chars = 1;
	while (nbr_chars > 0)
	{
		tmp = ft_calloc(BUFFER_SIZE + 1);
		if (!tmp)
			return (NULL);
		nbr_chars = read(fd, tmp, BUFFER_SIZE);
		if (nbr_chars == -1)
			return (free(helper), free(tmp), helper = NULL, NULL);
		else if (nbr_chars > 0 && !ft_strchr(tmp, '\n'))
		{
			helper = ft_free_and_join(helper, tmp);
			free(tmp);
		}
		else if (nbr_chars == 0 || ft_strchr(tmp, '\n'))
		{
			helper = ft_free_and_join(helper, tmp);
			return (free(tmp), helper);
		}
	}
	return (helper);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	while (0 == 0)
	{
		if (s[i] == (char )c)
			return (s + i);
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

char	*ft_free_and_join(char *helper, char *line)
{
	char	*tmp1;

	tmp1 = ft_strjoin(helper, line);
	free(helper);
	return (tmp1);
}

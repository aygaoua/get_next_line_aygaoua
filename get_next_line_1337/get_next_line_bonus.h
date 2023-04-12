/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 02:33:00 by azgaoua           #+#    #+#             */
/*   Updated: 2023/03/09 03:54:38 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char		*get_next_line(int fd);
char		*rdwr_and_search(int fd, char *helper);
char		*ft_strjoin(char *s1, char *s2);
int			search_nl(char *S);
void		ft_bzero(void *s, size_t nbr);
void		*ft_calloc(size_t count);
size_t		ft_strlen(const char *str);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_strchr(char *s, int c);
char		*ft_free(char *helper, char *line);

#endif

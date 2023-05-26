/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <shisaeki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:52:22 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/26 17:52:26 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_file(int fd, char *save)
{
	char	*buf;
	int		result;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	result = 1;
	while (!ft_strchr(save, '\n') && result)
	{
		result = read(fd, buf, BUFFER_SIZE);
		if (result == -1 || result == 0)
		{
			free(buf);
			return (NULL);
		}
		buf[result] = '\0';
		if (!save)
			save = ft_strdup(buf);
		else
			save = ft_strjoin(save, buf);
	}
	free(buf);
	return(save);
}

char	*get_line(char *save)
{
	char	*line;
	size_t	i;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] && save[i] !=  '\n')
		i++;
	line = (char *)malloc((sizeof(char) * (i + 1)));
	if (!line)
		return (NULL);
	ft_strlcpy(line, save, i + 1);
	return (line);
}

char	*reset_save(char *save)
{
	char *save_new;
	size_t	i;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	save_new = (char *)malloc(sizeof(char) * (ft_strlen(save) - i));
	if (!save_new)
		return (NULL);
	ft_strlcpy(save_new, &save[i + 1], ft_strlen(save) - i);
	free(save);
	return (save_new);
}

char	*get_next_line(int fd)
{
	static char *save;
	char *line;

	save = read_file(fd, save);
	line = get_line(save);
	if (!line)
		return (NULL);
	save = reset_save(save);
	return (line);
}


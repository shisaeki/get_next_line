/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <shisaeki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:52:22 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/29 18:43:25 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *save)
{
	char	*buf;
	ssize_t	result;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(save, '\n'))
	{
		result = read(fd, buf, BUFFER_SIZE);
		if (result == -1)
		{
			free(buf);
			free(save);
			return (NULL);
		}
		if (result == 0)
			break ;
		buf[result] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

char	*get_line(char *save)
{
	char	*line;
	size_t	i;

	i = 0;
	while (save[i] && save[i] != '\n')
	{
		i++;
	}
	line = (char *)malloc((sizeof(char) * (i + 2)));
	if (!line)
		return (NULL);
	ft_strlcpy(line, save, i + 2);
	return (line);
}

char	*reset_save(char *save)
{
	char	*save_new;
	size_t	i;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	save_new = (char *)malloc(sizeof(char) * (ft_strlen(save) - i));
	if (!save_new)
		return (NULL);
	ft_strlcpy(save_new, &save[i + 1], ft_strlen(save) - i);
	free(save);
	return (save_new);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	save[fd] = read_file(fd, save[fd]);
	if (!save[fd] || !(*save[fd]))
	{
		free(save[fd]);
		return (NULL);
	}
	line = get_line(save[fd]);
	if (!line)
		return (NULL);
	save[fd] = reset_save(save[fd]);
	return (line);
}

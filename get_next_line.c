/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:06:32 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/24 13:18:02 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	return (fd);
}

char	*read_file(int fd)
{
	char *buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	return(buf);
}

char	*get_next_line(int fd, char *buf)
{
	char *buf;
	static char *save;

	buf = read_file(fd)
	ft_strlcat(save, buf);
	if ()
}

int main(int argc, char **argv)
{
	char *filename;
	int fd;
	char *buf;
	static char *save;
	char *line;

	fd = open_file(argv[1]);

	buf = read_file(fd);
	printf("%s\n", buf);
	return (0);
}

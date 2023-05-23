/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:06:32 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/23 18:16:06 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char *filename;
	int fd;
	char *str;
	static char *save;

	filename = argv[1];
	fd = open(filename, O_RDONLY);

	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return ;

	read(fd, str, BUFFER_SIZE);
	str[BUFFER_SIZE] = '\0';

	printf("%s\n", str);
	return (0);
}

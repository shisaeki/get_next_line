/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shisaeki <shisaeki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:16:07 by shisaeki          #+#    #+#             */
/*   Updated: 2023/05/26 17:21:30 by shisaeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char *filename;
	int fd;
	char *save;
	char *line;

	fd = open(argv[1], O_RDONLY);

	for (int i = 0; i < 9; i++)
	{
		line = get_next_line(fd);
		if (!line)
		{
			printf("-----EOF-----");
			break;
		}
		printf("%d: %s\n", i, line);
	}
	return (0);
}

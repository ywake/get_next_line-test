/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 12:46:08 by ywake             #+#    #+#             */
/*   Updated: 2020/12/27 17:39:29 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	int fd;
	int rtn = 1;
	char *filename = argv[1];
	char *line[1];

	fd = open(filename, O_RDONLY);
//	fd = INT_MIN;
	printf("[main] fd : %d\n", fd);
	while (rtn > 0)
	{
		rtn = get_next_line(fd, line);
		printf("[main] line: '%s'(rtn: %d)\n", *line, rtn);
		free(*line);
		*line = NULL;
	}
	close(fd);

	printf("\nleak check...\n\n");
	while(1);
}

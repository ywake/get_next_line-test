/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 12:46:08 by ywake             #+#    #+#             */
/*   Updated: 2020/07/08 14:22:17 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"
// #include "../get_next_line/get_next_line.c"
// #include "../get_next_line/get_next_line_utils.c"

int main(int argc, char *argv[])
{
	(void)argc;
	// (void)argv;
	int fd;
	int rtn = 1;
	char *filename = argv[1];
	// char *filename = "test.txt";
	char **line = (char **)malloc(1 * sizeof(char *));

	fd = open(filename, O_RDONLY);
	printf("[main] fd : %d\n", fd);
	while (rtn > 0)
	{
		rtn = get_next_line(fd, line);
		// rtn = get_next_line(999, line);
		// rtn = get_next_line(0, line);
		// rtn = get_next_line(1, line);
		printf("[main] line: '%s'(%d)\n", *line, rtn);
		free(*line);
		*line = NULL;
	}
	close(fd);

	printf("\nleak check...\n\n");
	while(1);
}

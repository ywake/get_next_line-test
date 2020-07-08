/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 12:46:08 by ywake             #+#    #+#             */
/*   Updated: 2020/07/08 14:36:51 by ywake            ###   ########.fr       */
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
	int rtn1 = 1;
	int rtn2 = 1;
	char *file1 = argv[1];
	char *file2 = argv[2];
	// char *filename = "test.txt";
	char **line = (char **)malloc(1 * sizeof(char *));

	int fd1 = open(file1, O_RDONLY);
	int fd2 = open(file2, O_RDONLY);
	printf("[main] fd1: %d, fd2: %d\n", fd1, fd2);
	while (rtn1 > 0 || rtn2 > 0)
	{
		rtn1 = get_next_line(fd1, line);
		printf("[main fd=%d] line: '%s'(%d)\n", fd1, *line, rtn1);
		free(*line);
		*line = NULL;
		rtn2 = get_next_line(fd2, line);
		printf("[main fd=%d] line: '%s'(%d)\n", fd2, *line, rtn2);
		free(*line);
		*line = NULL;
	}
	close(fd1);
	close(fd2);

	printf("\nleak check...\n\n");
	while(1);
}

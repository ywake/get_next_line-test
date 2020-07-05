/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 12:46:08 by ywake             #+#    #+#             */
/*   Updated: 2020/07/05 04:01:20 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"
// #include "../get_next_line/get_next_line.c"
// #include "../get_next_line/get_next_line_utils.c"

int main(void)
{
	int fd;
	int rtn;
	char *filename = "test.txt";
	char **line = (char **)malloc(1 * sizeof(char *));

	fd = open(filename, O_RDONLY);
	printf("[main] fd : %d\n", fd);
	while ((rtn = get_next_line(fd, line)) > 0)
	{
		printf("[main] rtn: %d\n", rtn);
		printf("[main] line: %s\n", *line);
	}
}

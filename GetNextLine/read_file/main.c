* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:32:53 by mtocu             #+#    #+#             */
/*   Updated: 2023/11/23 17:47:05 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int fd;
	char *next_line;
	int count;

	count = 0;
	fd = open("filename3.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening a file");
		return (1);
	}

	int n_try = 0;

	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break;
		count++;
		printf("%s", next_line);
		free(next_line);
		next_line = NULL;
		++n_try;
	}
	close(fd);
	printf("\n");
	return (0);
}

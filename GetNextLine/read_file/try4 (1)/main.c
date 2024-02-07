/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:32:53 by mtocu             #+#    #+#             */
/*   Updated: 2023/11/24 13:15:29 by mtocu            ###   ########.fr       */
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

	while((next_line = get_next_line(fd)) != NULL)
	{
		printf("Line print from main %d is: %s", count,  next_line);
		free(next_line);
		++count;
	}
	close(fd);
	
	return (0);
}

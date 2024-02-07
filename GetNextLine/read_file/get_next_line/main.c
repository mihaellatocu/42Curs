/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:32:53 by mtocu             #+#    #+#             */
/*   Updated: 2024/01/29 13:59:07 by mtocu            ###   ########.fr       */
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
	//fd = open("big_line_with_nl", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening a file");
//		return (1);
	}

//	while ((next_line = get_next_line(fd)) != NULL)
	while(next_line)
	{
		if (count == 2)
		{
			close(fd);
			next_line = get_next_line(fd);
		}
		printf("Line print from main %d is: %s pointer: %p\n", count,  next_line, next_line);
		free(next_line);
		++count;
	}
	close(fd);
	
	return (0);
}

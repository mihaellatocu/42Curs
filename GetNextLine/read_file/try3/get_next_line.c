/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:40:47 by mtocu             #+#    #+#             */
/*   Updated: 2023/11/23 21:27:37 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
	char cup_buffer[5];
	int bytes_read;

	//cup_buffer = ft_calloc(3 + 1, sizeof(char));
	//if (cup_buffer == NULL)
	//	return (NULL);

	bytes_read = read(fd, cup_buffer, 5);
	if (bytes_read <= 0)
		return (NULL);
	return (cup_buffer);
}


#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd;
	char *next_line;
	int count = 0;

	fd = open("filename3.txt", O_RDONLY);
	next_line = get_next_line(fd);
	count++;
	printf("[%d]: %s",count,  next_line);
	//next_line = NULL;
	free(next_line);
	close(fd);
	
	return (0);
}


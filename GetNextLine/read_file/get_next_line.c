/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:14:44 by mtocu             #+#    #+#             */
/*   Updated: 2023/11/23 17:49:32 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include <string.h>
#include <stdlib.h>

static char	*read_from_file(char *text, int fd)
{
	int	bytes_read;
	char *portion_buffer;
	char *temp_text;

	portion_buffer = ft_calloc(sizeof(char), BUFFER_SIZE  + 1);//read size bytes at a time
	if (portion_buffer == NULL)
	{
		//free (portion_buffer);
		return (NULL);
	}
	bytes_read = 1;
	
	while (bytes_read > 0)
	{
		bytes_read = read(fd, portion_buffer, BUFFER_SIZE);//container for bytes read
		if (bytes_read == -1)
			return (free(portion_buffer), NULL);
		portion_buffer[bytes_read] = '\0';// ending each buffer cu \0
		temp_text = ft_strjoin(text, portion_buffer);// adding buffer into text
		free (text);
		text = temp_text;
		if (ft_strchr(temp_text, '\n'))
			break ;
	}
	free (portion_buffer);
	return (text);
}

char	*return_line(char *text)
{
	int i;
	char *line;
	int j;

	j = 0;
	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), i + 2);
	if (!line)
	{
		return (NULL);
	}
	while (j <= i) // copy all buffers inclusive \n up to \0
	{
		line[j] = text[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*return_remainder_text(char *text)
{
	int start;
	int len;
	char *remaining_line;

	int i = 0;
	len = ft_strlen(text);
	start = 0;
	while (text[start] && text[start] != '\n') // move the starting of the remaining text
		start++;
	if (!text[start])
	{
		free (text);
		return (NULL);
	}
	start++;
	remaining_line = ft_calloc(sizeof(char), (len - start + 1));
	if (!remaining_line)
	{
		return (NULL);
	}
	while (text[start] != '\0')
	{
		remaining_line[i] = text[start];
		start++;
		i++;
	}
	remaining_line[i] = '\0';
	
	return(remaining_line);
}

char	*get_next_line(int fd)
{
	static char *text = NULL;
	char *line;

	if (!text)
		text = ft_calloc (1, 1);
//	while (1) {
		text = read_from_file(text, fd);
		if (!text)
			return NULL;
	//	if (ft_strchr(text, '\n'))
	//		break ;
//	}

	line = return_line(text);

	text = return_remainder_text(text);
/*	if (!text || !*text)
	{
		free(text);
		return (NULL);
	}*/
	return ((char *)line);
}

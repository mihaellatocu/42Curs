/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:27:47 by mtocu             #+#    #+#             */
/*   Updated: 2023/12/13 18:33:52 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include <string.h>
#include <stdlib.h>

static char	*read_from_file(char *text, int fd)
{
	int		bytes_read;
	char	*whole_line;
	char	*temp_text;
	int		i;

	i = 0;
	//whole_line = ft_calloc(sizeof(char), ft_strlen(text) + 1);
	if (!text || BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	whole_line = ft_calloc(sizeof(char), ft_strlen(text) + 1);
	while (text[i])
	{
		whole_line[i] = text[i];
		i++;
	}
	while (!ft_strchr(whole_line, '\n'))
	{
		bytes_read = read(fd, text, BUFFER_SIZE);//container for bytes read
		if (bytes_read == 0 && *whole_line)
			return (whole_line);
		if (bytes_read <= 0)
		{
			free(whole_line);
			return (NULL);
		}
		text[bytes_read] = '\0';// ending each buffer cu \0
		temp_text = ft_strjoin(whole_line, text);// adding buffer into text
		free (whole_line);
		whole_line = temp_text;
	}
	return (whole_line);
}

char	*return_line(char *text)
{
	int		i;
	char	*line;
	int		j;

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
	if (!line)
		return (NULL);
	return (line);
}

void	move_remainder_text(char *text, char *whole_line)
{
	int	start;
	int	i;

	i = 0;
	start = 0;
	while (whole_line[start] && whole_line[start] != '\n') // move the starting of the remaining text
		start++;
	if (!whole_line[start])
	{
		//free (whole_line);
		text[0] = '\0';
		return ;
	}
	if (whole_line[start] == '\n')
		start++;
	while (whole_line[start] != '\0')
	{
		text[i] = whole_line[start];
		start++;
		i++;
	}
	text[i] = '\0';
}

char	*get_next_line(int fd)
{
	static char	text[BUFFER_SIZE + 1];
	char		*line;
	char		*whole_line;

	whole_line = read_from_file(text, fd);
	if (!whole_line || BUFFER_SIZE == 0)
		return (NULL);
	line = return_line(whole_line);

	move_remainder_text(text, whole_line);
	free(whole_line);
	//printf("Line length:  %d", ft_strlen(line));
	if (line)
		return ((char *)line);
	else
	{
		free(line);
		return (ft_calloc(1,1));
		//return (NULL);
	}
}

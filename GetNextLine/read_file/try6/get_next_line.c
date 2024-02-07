/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:27:47 by mtocu             #+#    #+#             */
/*   Updated: 2023/12/13 20:39:01 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include <string.h>
#include <stdlib.h>

char *extract_line (char *basin_buffer)
{
	int i;
	int j;
	char *line;

	i = 0;
	j = 0;
	while (basin_buffer && basin_buffer[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), i + 2);
	//if (!line)
	//	return (free(line), NULL);
	while (j <= i)
	{
		line[j] = basin_buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char *obtain_remaining (char *basin_buffer)
{
	int start;
	int i;
	char *temp;
	int len;

	i = 0;
	start = 0;
	len = strlen(basin_buffer);
	//temp = basin_buffer;
	while (basin_buffer[start] && basin_buffer[start] != '\n')
	{
		start++;
		--len;
	}
	temp = ft_calloc(len + 1, sizeof(char));
	while (temp[start] != '\0')
	{
		temp[i] = basin_buffer[start];
		start++;
		i++;
	}
	temp[i] = '\0';
	free (basin_buffer);
	return ((char *)temp);
}

char *append_buffer(char *basin_buffer, char *read_buffer)
{
	char *temp;

	temp = ft_strjoin(basin_buffer, read_buffer);
	free(basin_buffer);
	return (temp);
}

char *read_from_file(char *basin_buffer, int fd) 
{
	int bytes_read;
	char *cup_buffer;

	cup_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!cup_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read <= -1)
			return ( NULL);
		cup_buffer[bytes_read] = '\0';
		basin_buffer = append_buffer(basin_buffer, cup_buffer);
		if (ft_strchr(basin_buffer, '\n'))
			break;
	}
	return (cup_buffer);
}

char *get_next_line(int fd)
{
	static char *basin_buffer;
	char *line;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!basin_buffer)
		basin_buffer = ft_calloc(1, sizeof(char));
	if (!ft_strchr(basin_buffer, '\n'))
		basin_buffer = read_from_file(basin_buffer, fd);
	if(!basin_buffer)
		return (free(basin_buffer), NULL);
	line = extract_line(basin_buffer);
	basin_buffer = obtain_remaining(basin_buffer);
	return (line);
}	











/*
static char	*read_from_file(char *text, int fd)
{
	int		bytes_read;
	char	*whole_line;
	char	*temp_text;
	int		i;

	i = 0;
	whole_line = ft_calloc(sizeof(char), ft_strlen(text) + 1);
	while (text[i])
	{
		whole_line[i] = text[i];
		i++;
	}
	while (!ft_strchr(whole_line, '\n'))
	{
		bytes_read = read(fd, text, BUFFER_SIZE);//container for bytes read
		if (bytes_read <= 0)
			return (free(whole_line), NULL);
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
		free (whole_line);
		text[0] = '\0';
		return ;
	}
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
	if (!whole_line)
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
		return (NULL);
	}
}*/

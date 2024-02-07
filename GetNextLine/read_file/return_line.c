/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:16:53 by mtocu             #+#    #+#             */
/*   Updated: 2023/11/22 18:36:58 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

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
		return (NULL);

	while (j <= i) // copy all buffers inclusive \n up to \0
	{
		line[j] = text[j];
		j++;
			//	printf("%c\n", line[j]);
	}
	line[j] = '\0';
	return (line);
}

int	main(void)
{
	char *text = "ac asa\ndefew e cald\n si e bine";
	printf("%s", return_line(text));
}

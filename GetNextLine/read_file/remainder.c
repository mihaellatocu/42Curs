/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remainder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:18:16 by mtocu             #+#    #+#             */
/*   Updated: 2023/11/23 15:06:46 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*return_remainder_text(char *text)
{
	int start;
	int len;
	char *remaining_line;
	int i = 0;

	len = ft_strlen(text);
	start = 0;
	printf("text pointer: %p\n", text);
	printf("text : %s\n", text);
	while (text[start] && text[start] != '\n' && text[start] != '\0') // move the starting of the remaining text
		++start;
	if (!text[start])
	{
		free (text);
		return (NULL);
	}
	printf("text pointer: %p", text);
	printf("text: %s\n", text);
	while (text[start] && text[start] != '\n' && text[start] != '\0') // move the starting of the remaining text
	remaining_line = calloc(sizeof(char), (len - start + 1));
	if (!remaining_line)
	{
		free(remaining_line);
		return (NULL);
	}
	
	while (*text != '\0')
	{
		remaining_line[i] = text[start];
		start++;
		i++;
	printf("remainingline pointer: %p\n", remaining_line);
	}
	printf("remainingline pointer: %p\n", remaining_line);

	remaining_line[i] = '\0';
	printf("remainingline string: %s\n", remaining_line);
	return(remaining_line);
}
char	*ft_strdup( char *s)
{
	char	*copy;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	copy = (char *)malloc(sizeof(const char) * len + 1);
	while (s[i] != '\0')
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
int	main(void)
{
	char *text = ft_strdup("acasa\npropozitia nr2\n propoz nr 3");
	return_remainder_text(text);	
//	printf("%s\n", return_remainder_text(text));
//	free(text);
	return (0);
}

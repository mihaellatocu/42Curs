/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:16:58 by mtocu             #+#    #+#             */
/*   Updated: 2023/12/13 18:23:52 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


char *get_next_line(int fd)
{
	int	bytes_read;
	int cup_buffer = ft_calloc(3 + 1, sizeof(char));

	bytes_read = read(fd, cup_buffer, 3);

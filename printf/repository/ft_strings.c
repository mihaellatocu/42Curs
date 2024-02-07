/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:26:16 by mtocu             #+#    #+#             */
/*   Updated: 2023/12/01 14:27:03 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <stdint.h>
#include <limits.h>

int	print_char(int c)
{
	return (write (1, &c, 1));
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (print_str("(null)"));
	while (*str)
	{
		print_char((int)*str);
		++count;
		++str;
	}
	return (count);
}

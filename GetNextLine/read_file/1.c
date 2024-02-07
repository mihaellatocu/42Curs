/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:50:41 by mtocu             #+#    #+#             */
/*   Updated: 2023/11/23 13:18:48 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void) {
FILE *fptr;

//create a file
// this is to amend fptr = fopen("filename3.txt", "a");
//fprintf(fptr, "\nrandul 3\nrandul4");
fptr = fopen("filename3.txt", "r");
if (fptr == NULL)
	printf("Not able to open the file");
//fprintf(fptr, "\nAdditional text");
char myString[100];
while (fgets(myString, 100, fptr))
	printf("%s", myString);
fclose(fptr);
return (0);
}

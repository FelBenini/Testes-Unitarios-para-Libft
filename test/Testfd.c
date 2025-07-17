/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Testfd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:33:45 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/17 14:22:20 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include "unity.h"
#include <unistd.h>

void function_to_iterate_putchar(char c)
{
	int file;
	char string[2];
	char ch[] = {c, '\0'};
	FILE *fptr;
	fptr = fopen("./test/file.txt", "w");
	fclose(fptr);
	file = open("./test/file.txt", O_RDWR);
	ft_putchar_fd(c, file);
	close(file);
	fptr = fopen("./test/file.txt", "r");
	fgets(string, 2, fptr);
	TEST_ASSERT_EQUAL_STRING(ch, string);
	fclose(fptr);
	remove("./test/file.txt");
}

void test_putcharfd()
{
	int i = 0;
	char str[] = "adaghHBEDASfga12342365\t\narqa3tmOPQRXYZ";
	while (str[i])
	{
		function_to_iterate_putchar(str[i]);
		i++;
	}
}

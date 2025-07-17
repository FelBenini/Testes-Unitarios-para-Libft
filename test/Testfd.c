/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Testfd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:33:45 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/17 18:01:48 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include "unity.h"
#include <unistd.h>
#include <string.h>

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

void function_to_iterate_putstr(const char *input)
{
    FILE *fptr;
    const char *filepath = "./test/file.txt";
    char buffer[256] = {0};
    fptr = fopen(filepath, "w");
    TEST_ASSERT_NOT_NULL_MESSAGE(fptr, "Failed to open file for writing");
    fclose(fptr);
    int fd = open(filepath, O_WRONLY);
    TEST_ASSERT_NOT_EQUAL_MESSAGE(-1, fd, "Failed to open file descriptor");
    ft_putstr_fd((char *)input, fd);
    close(fd);
    fptr = fopen(filepath, "r");
    TEST_ASSERT_NOT_NULL_MESSAGE(fptr, "Failed to open file for reading");
    size_t read_len = fread(buffer, 1, sizeof(buffer) - 1, fptr);
    buffer[read_len] = '\0';
    fclose(fptr);
    TEST_ASSERT_EQUAL_STRING_MESSAGE(input, buffer, "Mismatch between input and file content");
    remove(filepath);
}

void test_putstr_fd(void)
{
    const char *test_strings[] = {
        "string1",
        "string2",
        "BANANA",
        "fasetgsrghs",
        "gry90562479",
        "",
        "a",
        "This is a longer test string with spaces!",
        "SpecialChars!@#%^&*()_+",
        NULL // Sentinel value
    };

    for (int i = 0; test_strings[i] != NULL; i++) {
        function_to_iterate_putstr(test_strings[i]);
    }
}

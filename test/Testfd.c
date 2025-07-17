/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Testfd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:33:45 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/17 18:30:14 by fbenini-         ###   ########.fr       */
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
    fclose(fptr);
    int fd = open(filepath, O_WRONLY);
    ft_putstr_fd((char *)input, fd);
    close(fd);
    fptr = fopen(filepath, "r");
    size_t read_len = fread(buffer, 1, sizeof(buffer) - 1, fptr);
    buffer[read_len] = '\0';
    fclose(fptr);
    TEST_ASSERT_EQUAL_STRING(input, buffer);
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
        NULL
    };

    for (int i = 0; test_strings[i] != NULL; i++) {
        function_to_iterate_putstr(test_strings[i]);
    }
}

void function_to_iterate_putendl(const char *input)
{
    FILE *fptr;
    const char *filepath = "./test/file.txt";
    char buffer[256] = {0};
    fptr = fopen(filepath, "w");
    fclose(fptr);
    int fd = open(filepath, O_WRONLY);
    ft_putendl_fd((char *)input, fd);
    close(fd);
    fptr = fopen(filepath, "r");
    size_t read_len = fread(buffer, 1, sizeof(buffer) - 1, fptr);
    buffer[read_len] = '\0';
    fclose(fptr);
    char expected[256] = {0};
    snprintf(expected, sizeof(expected), "%s\n", input);
    TEST_ASSERT_EQUAL_STRING(expected, buffer);
    remove(filepath);
}

void test_putendl_fd(void)
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
        NULL
    };

    for (int i = 0; test_strings[i] != NULL; i++) {
        function_to_iterate_putendl(test_strings[i]);
    }
}

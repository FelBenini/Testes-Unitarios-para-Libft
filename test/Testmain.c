/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:18:47 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/14 14:44:06 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "../src/libft.h"
#include <string.h>
#include <ctype.h>
#include <bsd/string.h>
#include <stdlib.h>

void setUp() {}
void tearDown() {}

void test_atoi()
{
	char *src[] = {"-4235", "31234", "   445", "     43254bc34", "-1", "0", "-+2222", "+123", "--123", " +42", "", "-2147483648", "2147483647", 0};
	int i = 0;
	while (src[i])
	{
		TEST_ASSERT_EQUAL(atoi(src[i]), ft_atoi(src[i]));
		i++;
	}
}

void test_bzero()
{
	char src1[] = "BANANA";
	char src2[] = "BANANA";
	bzero(src1, sizeof(src1));
	ft_bzero(src2, sizeof(src2));
	TEST_ASSERT_EQUAL_MEMORY(src1, src2, sizeof(src2));
}

void test_calloc() {
    int *std = (int *)calloc(5, sizeof(int));
    int *ft = (int *)ft_calloc(5, sizeof(int));
    TEST_ASSERT_NOT_NULL(std);
    TEST_ASSERT_NOT_NULL(ft);
    for (int i = 0; i < 5; i++) {
        TEST_ASSERT_EQUAL_INT(std[i], ft[i]);
    }
    free(std);
    free(ft);

    TEST_ASSERT_NULL(ft_calloc(SIZE_MAX, 2));

    char *c_std = (char *)calloc(1, 1);
    char *c_ft = (char *)ft_calloc(1, 1);
    TEST_ASSERT_NOT_NULL(c_std);
    TEST_ASSERT_NOT_NULL(c_ft);
    TEST_ASSERT_EQUAL_CHAR(*c_std, *c_ft);
    free(c_std);
    free(c_ft);

    void *large_std = calloc(10000, sizeof(int));
    void *large_ft = ft_calloc(10000, sizeof(int));
    TEST_ASSERT_NOT_NULL(large_std);
    TEST_ASSERT_NOT_NULL(large_ft);
    free(large_std);
    free(large_ft);
}

void test_isalnum()
{
	char *equals_true = "wABfsdgbfhdbnxm1234567890mnop";
	char *equals_false = "\n\t\r\v =+><?";
	int i = 0;
	while (equals_false[i])
	{
		TEST_ASSERT_FALSE(ft_isalnum(equals_false[i]));
		i++;
	}
	i = 0;
	while (equals_true[i])
	{
		TEST_ASSERT_TRUE(ft_isalnum(equals_true[i]));
		i++;
	}
}

void test_isalpha()
{
	char *equals_true = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *equals_false = "\n\t\r\v =+><?0123456789";
	int i = 0;
	while (equals_false[i])
	{
		TEST_ASSERT_FALSE(ft_isalpha(equals_false[i]));
		i++;
	}
	i = 0;
	while (equals_true[i])
	{
		TEST_ASSERT_TRUE(ft_isalpha(equals_true[i]));
		i++;
	}
}

void test_isascii()
{
	for (int i = 0; i <= 127; i++)
		TEST_ASSERT_TRUE(ft_isascii(i));
	for (int i = 128; i < 200; i++)
		TEST_ASSERT_FALSE(ft_isascii(i));
}

void test_isdigit()
{
	for (int i = '0'; i <= '9'; i++)
		TEST_ASSERT_TRUE(ft_isdigit(i));
	char *non_digits = "ABCxyz\n\t !@#";
	int i = 0;
	while (non_digits[i])
	{
		TEST_ASSERT_FALSE(ft_isdigit(non_digits[i]));
		i++;
	}
}

void test_isprint()
{
	for (int i = 32; i <= 126; i++)
		TEST_ASSERT_TRUE(ft_isprint(i));
	for (int i = 0; i < 32; i++)
		TEST_ASSERT_FALSE(ft_isprint(i));
	TEST_ASSERT_FALSE(ft_isprint(127));
}

void test_memchr()
{
	const char s1[] = "abcdef";
	const char s2[] = "";
	const char s3[] = "abcf";
	const char s4[] = "abc\0eg";
	TEST_ASSERT_EQUAL(memchr(s1, 'c', 6), ft_memchr(s1, 'c', 6));
	TEST_ASSERT_EQUAL(memchr(s2, 'a', 6), ft_memchr(s2, 'a', 6));
	TEST_ASSERT_EQUAL(memchr(s3, 0, 6), ft_memchr(s3, 0, 6));
	TEST_ASSERT_EQUAL(memchr(s4, 'e', 4), ft_memchr(s4, 'e', 4));
	TEST_ASSERT_EQUAL(memchr(s4, 'e', 6), ft_memchr(s4, 'e', 6));
	TEST_ASSERT_EQUAL_PTR(NULL, ft_memchr(s1, 'z', 6));
}

void test_memcmp()
{
	char s1[] = "abcdef";
	char s2[] = "abcdef";
	char s3[] = "abcdeg";
	char s4[] = "abcde";
	char s5[] = "abc\0ef";
	char s6[] = "abc\0eg";
	TEST_ASSERT_EQUAL(memcmp(s1, s2, 6), ft_memcmp(s1, s2, 6));
	TEST_ASSERT_EQUAL(memcmp(s1, s3, 6), ft_memcmp(s1, s3, 6));
	TEST_ASSERT_EQUAL(memcmp(s5, s6, 6), ft_memcmp(s5, s6, 6));
	TEST_ASSERT_EQUAL(memcmp(s1, s3, 3), ft_memcmp(s1, s3, 3));
	TEST_ASSERT_EQUAL(memcmp(s1, s3, 0), ft_memcmp(s1, s3, 0));
	TEST_ASSERT_EQUAL(memcmp(s1, s4, 5), ft_memcmp(s1, s4, 5));
}

void test_memcpy()
{
	char src1[] = "Tutorialspoint";
	char src2[] = "";
	char src3[] = "kloi";
	char dest1[50] = "Heloooo!!";
	char dest2[50] = "Heloooo!!";
	char dest3[50] = "";
	char dest4[50] = "";
	char dest5[50] = "al";
	char dest6[50] = "al";

	TEST_ASSERT_EQUAL_MEMORY(memcpy(dest1, src1, strlen(src1) + 1), ft_memcpy(dest2, src1, strlen(src1) + 1), strlen(src1) + 1);
	TEST_ASSERT_EQUAL_MEMORY(memcpy(dest3, src2, 5), ft_memcpy(dest4, src2, 5), 5);
	TEST_ASSERT_EQUAL_MEMORY(memcpy(dest5, src3, 1), ft_memcpy(dest6, src3, 1), 1);
}

void test_memmove()
{
	char buf1[30], buf2[30];
	strcpy(buf1, "abcdef123456");
	strcpy(buf2, "abcdef123456");
	ft_memmove(buf1 + 2, buf1, 8);
	memmove(buf2 + 2, buf2, 8);
	TEST_ASSERT_EQUAL_STRING(buf2, buf1);

	strcpy(buf1, "abcdef123456");
	strcpy(buf2, "abcdef123456");
	ft_memmove(buf1, buf1 + 6, 6);
	memmove(buf2, buf2 + 6, 6);
	TEST_ASSERT_EQUAL_STRING(buf2, buf1);

	strcpy(buf1, "abcdef123456");
	strcpy(buf2, "abcdef123456");
	ft_memmove(buf1, buf1 + 2, 8);
	memmove(buf2, buf2 + 2, 8);
	TEST_ASSERT_EQUAL_STRING(buf2, buf1);

	strcpy(buf1, "abcdef123456");
	strcpy(buf2, "abcdef123456");
	ft_memmove(buf1 + 4, buf1, 0);
	memmove(buf2 + 4, buf2, 0);
	TEST_ASSERT_EQUAL_STRING(buf2, buf1);

	strcpy(buf1, "abcdef123456");
	strcpy(buf2, "abcdef123456");
	ft_memmove(buf1, buf1, 12);
	memmove(buf2, buf2, 12);
	TEST_ASSERT_EQUAL_STRING(buf2, buf1);
}

void test_memset()
{
	char src1[] = "BANANA";
	char src2[] = "BANANA";
	TEST_ASSERT_EQUAL_MEMORY(memset(src1, 'A', sizeof(src1)), ft_memset(src2, 'A', sizeof(src2)), sizeof(src2));
}

void test_strchr()
{
	const char s1[] = "abcdef";
	const char s2[] = "";
	const char s3[] = "abcdeg";
	const char s4[] = "abc\0eg";
	TEST_ASSERT_EQUAL_STRING(strchr(s1, 'c'), ft_strchr(s1, 'c'));
	TEST_ASSERT_EQUAL_STRING(strchr(s3, 0), ft_strchr(s3, 0));
	TEST_ASSERT_EQUAL_STRING(strchr(s4, 'e'), ft_strchr(s4, 'e'));
	TEST_ASSERT_NULL(ft_strchr(s2, 'a'));
	TEST_ASSERT_NULL(ft_strchr(s1, 'x'));
}

void test_strdup()
{
	char *src[] = {"BANANA", "4234523", "MANGA", "Vibe Coding", "", " ", "\n\t", 0};
	int i = 0;
	while (src[i])
	{
		char *str = strdup(src[i]);
		char *ft_str = ft_strdup(src[i]);
		TEST_ASSERT_EQUAL_STRING(str, ft_str);
		free(str);
		free(ft_str);
		i++;
	}
}

void test_strlcat()
{
	char dst1[20], dst2[20];

	strcpy(dst1, "Hello");
	strcpy(dst2, "Hello");
	TEST_ASSERT_EQUAL_UINT(strlcat(dst1, " World", 20), ft_strlcat(dst2, " World", 20));
	TEST_ASSERT_EQUAL_STRING(dst1, dst2);
	strcpy(dst1, "Hello");
	strcpy(dst2, "Hello");
	TEST_ASSERT_EQUAL_UINT(strlcat(dst1, " World", 3), ft_strlcat(dst2, " World", 3));
	TEST_ASSERT_EQUAL_STRING(dst1, dst2);
	strcpy(dst1, "Hello");
	strcpy(dst2, "Hello");
	TEST_ASSERT_EQUAL_UINT(strlcat(dst1, "", 10), ft_strlcat(dst2, "", 10));
	TEST_ASSERT_EQUAL_STRING(dst1, dst2);
	strcpy(dst1, "");
	strcpy(dst2, "");
	TEST_ASSERT_EQUAL_UINT(strlcat(dst1, "Hello", 10), ft_strlcat(dst2, "Hello", 10));
	TEST_ASSERT_EQUAL_STRING(dst1, dst2);
	strcpy(dst1, "Test");
	strcpy(dst2, "Test");
	TEST_ASSERT_EQUAL_UINT(strlcat(dst1, "Add", 0), ft_strlcat(dst2, "Add", 0));
	TEST_ASSERT_EQUAL_STRING(dst1, dst2);
	strcpy(dst1, "123456789");
	strcpy(dst2, "123456789");
	TEST_ASSERT_EQUAL_UINT(strlcat(dst1, "A", 10), ft_strlcat(dst2, "A", 10));
	TEST_ASSERT_EQUAL_STRING(dst1, dst2);
	strcpy(dst1, "Full");
	strcpy(dst2, "Full");
	TEST_ASSERT_EQUAL_UINT(strlcat(dst1, "Buffer", 5), ft_strlcat(dst2, "Buffer", 5));
	TEST_ASSERT_EQUAL_STRING(dst1, dst2);
}

void test_strlen()
{
	char *src[] = {"-4235", "31234", "   445", "     43254bc34", "-1", "BANANA", "MANGA", "TRYHARDER", "0", "", " ", "\n\t", 0};
	int i = 0;
	while (src[i])
	{
		TEST_ASSERT_EQUAL(strlen(src[i]), ft_strlen(src[i]));
		i++;
	}
}

void test_strncmp()
{
	char src1[] = "BANANA";
	char src2[] = "BANANA";
	char src3[] = "BANUNU";
	char src4[] = "BAN";
	char src5[] = "BANN";
	TEST_ASSERT_EQUAL(strncmp(src1, src2, 5), ft_strncmp(src1, src2, 5));
	TEST_ASSERT_EQUAL(strncmp(src1, src3, 5), ft_strncmp(src1, src3, 5));
	TEST_ASSERT_EQUAL(strncmp(src4, src5, 5), ft_strncmp(src4, src5, 5));
	TEST_ASSERT_EQUAL(strncmp(src4, src5, 4), ft_strncmp(src4, src5, 4));
	TEST_ASSERT_EQUAL(strncmp("ABC", "abc", 0), ft_strncmp("ABC", "abc", 0));
}

void test_strnstr()
{
	TEST_ASSERT_EQUAL_STRING(strnstr("Felipe Benini", "Be", 13), ft_strnstr("Felipe Benini", "Be", 13));
	TEST_ASSERT_EQUAL_PTR(strnstr("Felipe Benini", "xyz", 13), ft_strnstr("Felipe Benini", "xyz", 13));
	TEST_ASSERT_EQUAL_PTR(strnstr("short", "longneedle", 10), ft_strnstr("short", "longneedle", 10));
	TEST_ASSERT_EQUAL_PTR(strnstr("Felipe Benini", "Benini", 6), ft_strnstr("Felipe Benini", "Benini", 6));
	TEST_ASSERT_EQUAL_STRING(strnstr("Felipe Benini", "Benini", 13), ft_strnstr("Felipe Benini", "Benini", 13));
	TEST_ASSERT_EQUAL_STRING(strnstr("Felipe", "", 6), ft_strnstr("Felipe", "", 6));
	TEST_ASSERT_EQUAL_STRING(strnstr("", "", 0), ft_strnstr("", "", 0));
	TEST_ASSERT_EQUAL_PTR(strnstr("", "abc", 3), ft_strnstr("", "abc", 3));
	TEST_ASSERT_EQUAL_PTR(strnstr("Felipe", "Fe", 0), ft_strnstr("Felipe", "Fe", 0));
	TEST_ASSERT_EQUAL_STRING(strnstr("Hello world", "Hello", 11), ft_strnstr("Hello world", "Hello", 11));
	TEST_ASSERT_EQUAL_STRING(strnstr("Hello world", "world", 11), ft_strnstr("Hello world", "world", 11));
	TEST_ASSERT_EQUAL_PTR(strnstr("abcdef", "cdeZ", 6), ft_strnstr("abcdef", "cdeZ", 6));
}

void test_strrchr()
{
	const char s1[] = "abcdef";
	const char s2[] = "";
	const char s3[] = "abcdeg";
	const char s4[] = "abc\0eg";
	TEST_ASSERT_EQUAL_STRING(strrchr(s1, 'c'), ft_strrchr(s1, 'c'));
	TEST_ASSERT_EQUAL_STRING(strrchr(s3, 0), ft_strrchr(s3, 0));
	TEST_ASSERT_EQUAL_STRING(strrchr(s4, 'e'), ft_strrchr(s4, 'e'));
	TEST_ASSERT_NULL(ft_strrchr(s2, 'a'));
	TEST_ASSERT_NULL(ft_strrchr(s1, 'z'));
}

void test_tolower()
{
	char *src = "badskdfbasdfdsOfasa\t\nz\v\rdafbxlspoqvcx";
	int i = 0;
	while (src[i])
	{
		TEST_ASSERT_EQUAL(tolower(src[i]), ft_tolower(src[i]));
		i++;
	}
}

void test_toupper()
{
	char *src = "bOcgfs2mMnf\tasdghdMzxto3Pcx0\nzm";
	int i = 0;
	while (src[i])
	{
		TEST_ASSERT_EQUAL(toupper(src[i]), ft_toupper(src[i]));
		i++;
	}
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_atoi);
	RUN_TEST(test_bzero);
	RUN_TEST(test_isalnum);
	RUN_TEST(test_isalpha);
	RUN_TEST(test_isascii);
	RUN_TEST(test_isdigit);
	RUN_TEST(test_isprint);
	RUN_TEST(test_memchr);
	RUN_TEST(test_memcmp);
	RUN_TEST(test_memcpy);
	RUN_TEST(test_memmove);
	RUN_TEST(test_memset);
	RUN_TEST(test_strchr);
	RUN_TEST(test_strdup);
	RUN_TEST(test_strlen);
	RUN_TEST(test_strncmp);
	RUN_TEST(test_strnstr);
	RUN_TEST(test_strrchr);
	RUN_TEST(test_tolower);
	RUN_TEST(test_toupper);
	RUN_TEST(test_calloc);
	RUN_TEST(test_strlcat);
	UNITY_END();
	return 0;
}


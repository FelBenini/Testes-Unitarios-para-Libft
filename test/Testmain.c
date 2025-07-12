/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsilveir <wsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:34:39 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/12 15:21:08 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "../src/libft.h"
#include <string.h>
#include <ctype.h>

void setUp()
{

}

void tearDown()
{

}

void	test_strlen()
{
	char *src[] = {"-4235", "31234", "   445", "     43254bc34", "-1", "BANANA", "MANGA", "TRYHARDER", "0", 0};
	int i = 0;
	while (src[i])
	{
		TEST_ASSERT_EQUAL(strlen(src[i]), ft_strlen(src[i]));
		i++;
	}
}

void	test_strdup()
{
	char *src[] = {"BANANA", "4234523", "MANGA", "Vibe Coding", 0};
	int i = 0;
	while (src[i])
	{
		char *str = strdup(src[i]);
		char *ft_str = ft_strdup(src[i]);
		TEST_ASSERT_EQUAL_MEMORY(str, ft_str, sizeof(src[i]));
		free(str);
		free(ft_str);
		i++;
	}
}

void	test_atoi()
{
	char *src[] = {"-4235", "31234", "   445", "     43254bc34", "-1", "0", 0};
	int i = 0;
	while (src[i])
	{
		TEST_ASSERT_EQUAL(atoi(src[i]), ft_atoi(src[i]));
		i++;
	}
}

void	test_memset()
{
	char src2[] = "BANANA";
	char src1[] = "BANANA";
	TEST_ASSERT_EQUAL_MEMORY(memset(src1, 'A', sizeof(src1)), ft_memset(src2, 'A', sizeof(src2)), sizeof(src2));
}

void	test_memcpy()
{
	const char src1[50], src2[50] = "Tutorialspoint";
	const char src3[50], src4[50] = "";
	const char src5[50], src6[50] = "kloi";
	char dest1[50], dest2[50] = "Heloooo!!";
	char dest3[50], dest4[50] = "";
	char dest5[50], dest6[50] = "al";
	TEST_ASSERT_EQUAL_MEMORY(memcpy(dest1, src1, strlen(src1) + 1), ft_memcpy(dest2, src2, strlen(src2) + 1), sizeof(dest2));
	TEST_ASSERT_EQUAL_MEMORY(memcpy(dest3, src3, 5), ft_memcpy(dest4, src4, 5), sizeof(dest4));
	TEST_ASSERT_EQUAL_MEMORY(memcpy(dest5, src5, 1), ft_memcpy(dest6, src6, 1), sizeof(dest6));
}

void	test_strncmp()
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
}

void	test_bzero()
{
	char src2[] = "BANANA";
	char src1[] = "BANANA";
	bzero(src1, sizeof(src1));
	ft_bzero(src2, sizeof(src2));
	TEST_ASSERT_EQUAL_MEMORY(src1, src2, sizeof(src2));
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

void test_isprint()
{
	char *equals_true = "C16mJGAGI LOPcfbxZBGFDg";
	char *equals_false = "\n\t\r\v";
	int i = 0;
	while (equals_true[i])
	{
		TEST_ASSERT_TRUE(ft_isprint(equals_true[i]));
		i++;
	}
	i = 0;
	while (equals_false[i])
	{
		TEST_ASSERT_FALSE(ft_isprint(equals_false[i]));
		i++;
	}
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

void test_isdigit()
{
	TEST_ASSERT_FALSE(ft_isdigit('C'));
	TEST_ASSERT_TRUE(ft_isdigit('1'));
	TEST_ASSERT_FALSE(ft_isdigit('\n'));
	TEST_ASSERT_FALSE(ft_isdigit('+'));
}

void test_isascii()
{
	TEST_ASSERT_TRUE(ft_isascii('C'));
	TEST_ASSERT_TRUE(ft_isascii('1'));
	TEST_ASSERT_FALSE(ft_isascii(0x80));
	TEST_ASSERT_TRUE(ft_isascii('+'));
}

void test_memmove()
{
    char buf1[30];
    char buf2[30];

    // 1. Overlapping copy: dest inside src (forward copy)
    strcpy(buf1, "abcdef123456");
    strcpy(buf2, "abcdef123456");
    ft_memmove(buf1 + 2, buf1, 8);
    memmove(buf2 + 2, buf2, 8);
    TEST_ASSERT_EQUAL_STRING(buf2, buf1);

    // 2. Non-overlapping copy: src and dest completely separate
    strcpy(buf1, "abcdef123456");
    strcpy(buf2, "abcdef123456");
    ft_memmove(buf1, buf1 + 6, 6);  // copy "123456" to start
    memmove(buf2, buf2 + 6, 6);
    TEST_ASSERT_EQUAL_STRING(buf2, buf1);

    // 3. Overlapping copy: src inside dest (backward copy)
    strcpy(buf1, "abcdef123456");
    strcpy(buf2, "abcdef123456");
    ft_memmove(buf1, buf1 + 2, 8);  // move "cdef1234" to start
    memmove(buf2, buf2 + 2, 8);
    TEST_ASSERT_EQUAL_STRING(buf2, buf1);

    // 4. Copy zero bytes (should do nothing)
    strcpy(buf1, "abcdef123456");
    strcpy(buf2, "abcdef123456");
    ft_memmove(buf1 + 4, buf1, 0);
    memmove(buf2 + 4, buf2, 0);
    TEST_ASSERT_EQUAL_STRING(buf2, buf1);

    // 5. Copy full buffer (no overlap)
    strcpy(buf1, "abcdef123456");
    strcpy(buf2, "abcdef123456");
    ft_memmove(buf1 + 15, buf1, 12);
    memmove(buf2 + 15, buf2, 12);
    TEST_ASSERT_EQUAL_STRING(buf2, buf1);

    // 6. Copy overlapping buffers where src == dest (should be no-op)
    strcpy(buf1, "abcdef123456");
    strcpy(buf2, "abcdef123456");
    ft_memmove(buf1, buf1, 12);
    memmove(buf2, buf2, 12);
    TEST_ASSERT_EQUAL_STRING(buf2, buf1);
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

void test_memchr()
{
	const char s1[] = "abcdef";
	const char s2[] = "";
	const char s3[] = "abcdeg";
	const char s4[] = "abc\0eg";

	TEST_ASSERT_EQUAL(memchr(s1, 'c', 6), ft_memchr(s1, 'c', 6));

	TEST_ASSERT_EQUAL(memchr(s2, 'a', 6), ft_memchr(s2, 'a', 6));

	TEST_ASSERT_EQUAL(memchr(s3, 0, 6), ft_memchr(s3, 0, 6));

	TEST_ASSERT_EQUAL(memchr(s4, 'e', 4), ft_memchr(s4, 'e', 4));
	
	TEST_ASSERT_EQUAL(memchr(s4, 'e', 6), ft_memchr(s4, 'e', 6));
}

void test_strchr()
{
	const char s1[] = "abcdef";
	const char s2[] = "";
	const char s3[] = "abcdeg";
	const char s4[] = "abc\0eg";

	TEST_ASSERT_EQUAL_STRING(strchr(s1, 'c'), ft_strchr(s1, 'c'));

	TEST_ASSERT_EQUAL_STRING(strchr(s2, 'a'), ft_strchr(s2, 'a'));

	TEST_ASSERT_EQUAL_STRING(strchr(s3, 0), ft_strchr(s3, 0));

	TEST_ASSERT_EQUAL_STRING(strchr(s4, 'e'), ft_strchr(s4, 'e'));
	
	TEST_ASSERT_EQUAL_STRING(strchr(s4, 'e'), ft_strchr(s4, 'e'));
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_strlen);
	RUN_TEST(test_strdup);
	RUN_TEST(test_atoi);
	RUN_TEST(test_memset);
	RUN_TEST(test_strncmp);
	RUN_TEST(test_bzero);
	RUN_TEST(test_tolower);
	RUN_TEST(test_toupper);
	RUN_TEST(test_isprint);
	RUN_TEST(test_isalnum);
	RUN_TEST(test_isalpha);
	RUN_TEST(test_isascii);
	RUN_TEST(test_isdigit);
	RUN_TEST(test_memmove);
	RUN_TEST(test_memcmp);
	RUN_TEST(test_memchr);
	RUN_TEST(test_strchr);
	UNITY_END();

	return (0);
}

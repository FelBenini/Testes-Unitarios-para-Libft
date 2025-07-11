/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:34:39 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/11 14:27:46 by fbenini-         ###   ########.fr       */
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
	while (equals_false[i])
	{
		TEST_ASSERT_FALSE(ft_isprint(equals_false[i]));
		i++;
	}
	i = 0;
	while (equals_true[i])
	{
		TEST_ASSERT_TRUE(ft_isprint(equals_true[i]));
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
	RUN_TEST(test_isdigit);
	UNITY_END();

	return (0);
}

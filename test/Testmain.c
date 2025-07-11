/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:34:39 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/10 19:38:22 by fbenini-         ###   ########.fr       */
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
	TEST_ASSERT_EQUAL(strlen("BANANA"), ft_strlen("BANANA"));
	TEST_ASSERT_EQUAL(strlen("alguma coisa"), ft_strlen("alguma coisa"));
	TEST_ASSERT_EQUAL(strlen("picanhazinha"), ft_strlen("picanhazinha"));
}

void	test_strdup()
{
	TEST_ASSERT_EQUAL_MEMORY(strdup("BANANA"), ft_strdup("BANANA"), 6);
	TEST_ASSERT_EQUAL_STRING(strdup("BANANA"), ft_strdup("BANANA"));
}

void	test_atoi()
{
	TEST_ASSERT_EQUAL(atoi("-4234"), ft_atoi("-4234"));
	TEST_ASSERT_EQUAL(-3215, ft_atoi("   -+--3215"));
	TEST_ASSERT_EQUAL(atoi("4525634"), ft_atoi("4525634"));
	TEST_ASSERT_EQUAL(atoi("42ad34"), ft_atoi("42ad34"));
}

void	test_memset()
{
	char src2[] = "BANANA";
	char src1[] = "BANANA";
	TEST_ASSERT_EQUAL_MEMORY(memset(src1, 'A', sizeof(src1)), ft_memset(src2, 'A', sizeof(src2)), sizeof(src2));
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
	TEST_ASSERT_EQUAL(tolower('C'), ft_tolower('C'));
	TEST_ASSERT_EQUAL(tolower('b'), ft_tolower('b'));
	TEST_ASSERT_EQUAL(tolower('O'), ft_tolower('O'));
	TEST_ASSERT_EQUAL(tolower('p'), ft_tolower('p'));
}

void test_toupper()
{
	TEST_ASSERT_EQUAL(toupper('C'), ft_toupper('C'));
	TEST_ASSERT_EQUAL(toupper('b'), ft_toupper('b'));
	TEST_ASSERT_EQUAL(toupper('O'), ft_toupper('O'));
	TEST_ASSERT_EQUAL(toupper('p'), ft_toupper('p'));
}

void test_isprint()
{
	TEST_ASSERT_TRUE(ft_isprint('C'));
	TEST_ASSERT_TRUE(ft_isprint('1'));
	TEST_ASSERT_FALSE(ft_isprint('\n'));
	TEST_ASSERT_TRUE(ft_isprint('+'));
}

void test_isalnum()
{
	TEST_ASSERT_TRUE(ft_isalnum('C'));
	TEST_ASSERT_TRUE(ft_isalnum('1'));
	TEST_ASSERT_FALSE(ft_isalnum('\n'));
	TEST_ASSERT_FALSE(ft_isalnum('+'));
}

void test_isalpha()
{
	TEST_ASSERT_TRUE(ft_isalpha('C'));
	TEST_ASSERT_FALSE(ft_isalpha('1'));
	TEST_ASSERT_FALSE(ft_isalpha('\n'));
	TEST_ASSERT_FALSE(ft_isalpha('+'));
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
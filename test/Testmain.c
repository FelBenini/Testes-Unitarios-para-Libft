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

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_strlen);
	RUN_TEST(test_strdup);
	RUN_TEST(test_atoi);
	RUN_TEST(test_memset);
	RUN_TEST(test_bzero);
	RUN_TEST(test_tolower);
	UNITY_END();

	return (0);
}

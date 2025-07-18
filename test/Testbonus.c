/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Testbonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:29:25 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/18 13:59:45 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unity.h"

void test_lstnew()
{
	t_list	*node = ft_lstnew("Testing");
	TEST_ASSERT_EQUAL_STRING("Testing", node->content);
	TEST_ASSERT_NULL(node->next);
	free(node);
	int	arr[] = {0, 1, 2, 3, 4};
	node = ft_lstnew(arr);
	TEST_ASSERT_EQUAL_INT_ARRAY(arr, node->content, 5);
	TEST_ASSERT_NULL(node->next);
	free(node);
	node = ft_lstnew((void *)42);
	TEST_ASSERT_EQUAL_INT(42, node->content);
	TEST_ASSERT_NULL(node->next);
	free(node);
	node = ft_lstnew(NULL);
	TEST_ASSERT_NULL(node->content);
	TEST_ASSERT_NULL(node->next);
	free(node);
}

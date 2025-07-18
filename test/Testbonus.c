/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Testbonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:29:25 by fbenini-          #+#    #+#             */
/*   Updated: 2025/07/18 18:06:46 by fbenini-         ###   ########.fr       */
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

void test_lstadd_front(void)
{
	t_list	*head = NULL;
	t_list	*node1 = ft_lstnew("Node1");
	t_list	*node2 = ft_lstnew("Node2");

	ft_lstadd_front(&head, node1);
	TEST_ASSERT_EQUAL_PTR(node1, head);
	TEST_ASSERT_EQUAL_STRING("Node1", (char *)head->content);
	TEST_ASSERT_NULL(head->next);

	ft_lstadd_front(&head, node2);
	TEST_ASSERT_EQUAL_PTR(node2, head);
	TEST_ASSERT_EQUAL_STRING("Node2", (char *)head->content);
	TEST_ASSERT_EQUAL_PTR(node1, head->next);
	TEST_ASSERT_EQUAL_STRING("Node1", (char *)head->next->content);
	TEST_ASSERT_NULL(head->next->next);

	free(node1);
	free(node2);
}

void test_lstsize()
{
	t_list *head = NULL;
	t_list *node = ft_lstnew("Node1");
	t_list *node2 = ft_lstnew("Node2");
	TEST_ASSERT_EQUAL_INT(0, ft_lstsize(head));
	ft_lstadd_front(&head, node);
	ft_lstadd_front(&head, node2);
	TEST_ASSERT_EQUAL_INT(2, ft_lstsize(head));
	t_list *node3 = ft_lstnew("Node3");
	ft_lstadd_front(&head, node3);
	TEST_ASSERT_EQUAL_INT(3, ft_lstsize(head));
	free(node);
	free(node2);
	free(node3);
}

void test_lstlast()
{
	t_list *head = NULL;
	t_list *node = ft_lstnew("Node1");
	TEST_ASSERT_NULL(ft_lstlast(head));
	ft_lstadd_front(&head, node);
	TEST_ASSERT_EQUAL_STRING("Node1", ft_lstlast(head)->content);
	TEST_ASSERT_NULL(ft_lstlast(head)->next);
	t_list *node2 = ft_lstnew("Node2");
	ft_lstadd_front(&node2, head);
	TEST_ASSERT_EQUAL_STRING("Node2", ft_lstlast(head)->content);
	TEST_ASSERT_EQUAL_STRING("Node2", ft_lstlast(node)->content);
	TEST_ASSERT_EQUAL_STRING("Node2", ft_lstlast(node2)->content);
	while (head)
    {
        t_list *tmp = head->next;
        free(head);
        head = tmp;
    }
}

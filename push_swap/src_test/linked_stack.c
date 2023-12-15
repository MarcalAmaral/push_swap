/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:53:06 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/15 19:06:57 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_stack	*ft_newnode_stack(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *) ft_calloc(1, sizeof(t_stack));
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*ft_lstlast_stack(t_stack *stack)
{
	while (stack)
	{
		if (!stack->next)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

void	ft_append_stack(t_stack **head, t_stack **tail, t_stack *node)
{
	t_stack	*temp;
	t_stack	*temp1;

	if (!node)
		return ;
	if (!*head)
	{
		*head = node;
		*tail = node;
		return ;
	}
	/* Circular list */
	/* if have 1 element and introduce 2nd element proceed*/
	temp = *head;
	if (temp->next == NULL)
	{
		*head = node;
		*tail = temp;
		node->next = temp;
		node->prev = temp;
		temp->prev = node;
		temp->next = node;
	}
	else
	{
		/* If have 2 or more elements proceed */
		/* temp1 equals the last value of a list (temp1->next = first_value) : node equals the first value (node->prev = last_value)*/
		/* previous first value it will be the second value, with (prev == first_value && next == 3nd value)*/
		/* */
		temp1 = *tail;
		temp1->next = node;
		node->prev = temp1;
		node->next = temp;
		temp->prev = node;
		*head = node;
	}
	return ;
}

void	ft_print_linkedlist(t_stack **head, t_stack **tail)
{
	int i = 0;
	t_stack *temp;

	if (!*head)
		return ;
	temp = *head;
	while (temp)
	{
		printf("%d\n", temp->content);
		if (temp->next == *tail)
			break ;
		temp = temp->next;
		i++;
	}
	if (i > 1)
	{
		temp = temp->next;
		printf("%d\n", temp->content);
	}
	return ;
}

int	main(void)
{
	t_push	a;
	t_push	b;
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int arr1[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
	int i = 9;

	ft_bzero(&a, sizeof(t_push));
	ft_bzero(&b, sizeof(t_push));
	while (i >= 0)
	{
		ft_append_stack(&a.head, &a.tail, ft_newnode_stack(arr[i]));
		// ft_append_stack(&b.head, &b.tail, ft_newnode_stack(arr1[i]));
		i--;
	}
	// ft_print_linkedlist(&a.head, &a.tail);
	// printf("Stack A \n------------------------------------\n");
	// mov_swap(&a.head);
	// ft_print_linkedlist(&a.head, &a.tail);
	// printf("Stack A after 'sa' \n------------------------------------\n");
	// ft_print_linkedlist(&b.head, &b.tail);
	// printf("Stack B \n------------------------------------\n");
	// mov_swap(&b.head);
	// ft_print_linkedlist(&b.head, &b.tail);
	// printf("Stack B after 'sa' \n------------------------------------\n");


	move_push(&a, &b);
	printf("Stack B ==============================================\n");
	ft_print_linkedlist(&b.head, &b.tail);

	printf("Stack A ==============================================\n");
	ft_print_linkedlist(&a.head, &a.tail);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:53:06 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/18 14:39:34 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_stack	*ft_newnode_stack(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *) ft_calloc(1, sizeof(t_stack));
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
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
	t_stack *tail_p;

	if (!*head)
		return ;
	temp = *head;
	tail_p = *tail;
	while (temp)
	{
		printf("%d\n", temp->content);
		if (temp == *tail)
			break ;
		temp = temp->next;
		i++;
	}
	return ;
}

void	init_push(t_push *a, t_push *b, int *arr)
{
	int	i;

	ft_bzero(a, sizeof(t_push));
	ft_bzero(b, sizeof(t_push));
	i = matrix_int_lenght(arr) - 1;
	while (i >= 0)
	{
		ft_append_stack(&a->head, &a->tail, ft_newnode_stack(arr[i]));
		i--;
	}
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	t_push a;
	t_push b;
	int *arr;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n - Invalid num of args, pass one or more arguments\n", 2);
		return (1);
	}
	if (argc == 2 && argv[1])
	{
		arr = convert_str_arr(argv[1]);
		init_push(&a, &b, arr);
	}
	else if (argc > 2)
	{
		arr = convert_args_arr(argv);
		init_push(&a, &b, arr);
	}
	mov_swap(&a);
	ft_print_linkedlist(&a.head, &a.tail);
	printf("Stack A \n------------------------------------\n");
	return (0);
}

// int	main(void)
// {
// 	t_push	a;
// 	t_push	b;
// 	int		*arr;
// 	int		i;

// 	ft_bzero(&a, sizeof(t_push));
// 	ft_bzero(&b, sizeof(t_push));
// 	i = matrix_lenght(arr);
// 	while (i >= 0)
// 	{
// 		ft_append_stack(&a.head, &a.tail, ft_newnode_stack(arr[i]));
// 		ft_append_stack(&b.head, &b.tail, ft_newnode_stack(arr1[i]));
// 		i--;
// 	}
// 	// ft_print_linkedlist(&a.head, &a.tail);
// 	// printf("Stack A \n------------------------------------\n");
// 	// mov_swap(&a.head);
// 	// ft_print_linkedlist(&a.head, &a.tail);
// 	// printf("Stack A after 'sa' \n------------------------------------\n");
// 	// ft_print_linkedlist(&b.head, &b.tail);
// 	// printf("Stack B \n------------------------------------\n");
// 	// mov_swap(&b.head);
// 	// ft_print_linkedlist(&b.head, &b.tail);
// 	// printf("Stack B after 'sa' \n------------------------------------\n");

// 	mov_rrr(&a, &b);
// 	mov_rrr(&a, &b);
// 	mov_rrr(&a, &b);
// 	printf("Stack B ==============================================\n");
// 	ft_print_linkedlist(&b.head, &b.tail);
// 	printf("Stack A ==============================================\n");
// 	ft_print_linkedlist(&a.head, &a.tail);

// 	// move_push(&a, &b);
// 	// printf("Stack B ==============================================\n");
// 	// ft_print_linkedlist(&b.head, &b.tail);

// 	// printf("Stack A ==============================================\n");
// 	// ft_print_linkedlist(&a.head, &a.tail);
// 	// move_push(&b, &a);
// 	// printf("Stack B ==============================================\n");
// 	// ft_print_linkedlist(&b.head, &b.tail);

// 	// printf("Stack A ==============================================\n");
// 	// ft_print_linkedlist(&a.head, &a.tail);
// 	// move_push(&b, &a);
// 	// printf("Stack B ==============================================\n");
// 	// ft_print_linkedlist(&b.head, &b.tail);

// 	// printf("Stack A ==============================================\n");
// 	// ft_print_linkedlist(&a.head, &a.tail);
// 	return (0);
// }

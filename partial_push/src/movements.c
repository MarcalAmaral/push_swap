/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:48:20 by myokogaw          #+#    #+#             */
/*   Updated: 2024/01/06 13:01:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mov_swap(t_dlist *firstNode)
{
	int temp;

	ft_printf("\nMov Swap\n");
	if (!firstNode)
		return ;
	if (!firstNode->next)
		return ;
	else
	{
		temp = firstNode->content;
		firstNode->content = firstNode->next->content;
		firstNode->next->content = temp;
	}
}

void	mov_ss(t_dlist **a, t_dlist **b)
{
	ft_printf("\nMov SS\n");
	mov_swap(*a);
	mov_swap(*b);
	return ;
}

void	mov_push(t_dlist **src, t_dlist **dst)
{
	t_dlist *first;
	t_dlist *temp;

	ft_printf("\nMov Push\n");
	if (!*src)
		return ;
	first = *src;
	if (!first->next)
	{
		*src = NULL;
		first->next = *dst;
		if (first->next)
		{
			temp = first->next;
			temp->prev = first;
		}
		*dst = first;
		return ;
	}
	temp = first->next;
	temp->prev = NULL;
	*src = temp;
	first->next = *dst;
	*dst = first;
	return ;
}

void	mov_rotate(t_dlist **stack)
{
	t_dlist *temp;
	t_dlist *first;

	ft_printf("\nMov Rotate\n");
	if(!*stack)
		return ;
	first = *stack;
	if (!first->next)
		return ;
	*stack = first->next;
	temp = ft_lstlast_dlist(*stack);
	first->next = NULL;
	temp->next = first;
}

void	mov_rr(t_stacks *stacks)
{
	mov_rotate(stacks->a);
	mov_rotate(stacks->b);
}

void	mov_reverse_rotate(t_dlist **stack)
{
	t_dlist *temp;
	t_dlist *first;
	t_dlist *last;

	ft_printf("\nMov Reverse Rotate\n");
	if(!*stack)
		return ;
	first = *stack;
	if (!first->next)
		return ;
	last = ft_lstlast_dlist(*stack);
	temp = last->prev;
	temp->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack = last;
}

void	mov_rrr(t_stacks *stacks)
{
	mov_reverse_rotate(stacks->a);
	mov_reverse_rotate(stacks->b);
}

int	main(void)
{
	t_stacks stacks;
	int arr[] = {200, 2100, 2320, 0, -1299, 50};
	int lenght = sizeof(arr) / sizeof(*arr);
	int	i = 0;
	
	init_stack(arr, lenght, &stacks);
	ft_printf("Printing before move\n");
	ft_print_stacks(*stacks.a, *stacks.b);
	// mov_push(stacks.a, stacks.b);
	// mov_swap(*stacks.a);
	mov_push(stacks.a, stacks.b);
	mov_push(stacks.a, stacks.b);
	mov_push(stacks.a, stacks.b);
	mov_push(stacks.a, stacks.b);
	mov_push(stacks.a, stacks.b);
	mov_push(stacks.a, stacks.b);
	// mov_ss(stacks.a, stacks.b);
	// mov_rrr(&stacks);
	ft_printf("Printing after move\n");
	ft_print_stacks(*stacks.a, *stacks.b);
	// ft_printf("Printing after move\n");
	// ft_print_stacks(a, b);
	return (0);
}
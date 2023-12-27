/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:48:20 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/27 18:52:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mov_swap(t_list *firstNode)
{
	void *temp;

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

void	mov_ss(t_list **a, t_list **b)
{
	mov_swap(*a);
	mov_swap(*b);
	return ;
}

void	mov_push(t_list **src, t_list **dst)
{
	t_list *temp;

	if (!*src)
		return ;
	temp = *src;
	*src = temp->next;
	temp->next = *dst;
	*dst = temp;
	return ;
}

void	mov_rotate(t_list **stack)
{
	t_list *temp;
	t_list *first;

	if(!*stack)
		return ;
	first = *stack;
	if (!first->next)
		return ;
	*stack = first->next;
	temp = ft_lstlast(*stack);
	first->next = NULL;
	temp->next = first;
}

void	mov_reverse_rotate(t_list **stack)
{
	t_list *temp;
	t_list *first;

	if(!*stack)
		return ;
	if (!first->next)
		return ;
	last = ft_lstlast(*stack);
	last->next = *stack;
	*stack = last;
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
	// mov_push(stacks.a, stacks.b);
	// mov_ss(stacks.a, stacks.b);
	mov_rotate(stacks.a);
	ft_printf("Printing after move\n");
	ft_print_stacks(*stacks.a, *stacks.b);
	// ft_printf("Printing after move\n");
	// ft_print_stacks(a, b);
	return (0);
}
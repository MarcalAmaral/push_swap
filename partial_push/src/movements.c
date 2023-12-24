/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:48:20 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/23 17:08:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mov_swap(t_dlist *firstNode)
{
	int temp;

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

t_dlist *red_for_push(t_dlist **src)
{
	t_dlist *temp;
	t_dlist *temp1;
	
	if (!*src)
		return (NULL);
	temp = *src;
	if (temp->next == temp)
	{ 
		*src = NULL;
		return (temp);
	}
	*src = temp->next;
	temp1 = *src;
	temp1->prev = temp->prev;
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}

void	push_add_dst(t_dlist **dst, t_dlist *node)
{
	t_dlist *temp;

	if (!*dst)
	{
		node->next = node;
		node->prev = node;
		*dst = node;
		return ;
	}
	temp = *dst;
	if (temp->next == *dst)
	{
		temp->next = node;
		temp->prev = node;
		node->next = temp;
		node->prev = temp;
		*dst = node;
		return ;
	}
	node->next = temp;
	node->prev = temp->prev;
	temp->prev = node;
	*dst = node;
	return ;
}

void	mov_push(t_dlist **src, t_dlist **dst)
{
	t_dlist *temp;

	temp = red_for_push(src);
	if (!temp)
		return ;
	push_add_dst(dst, temp);
	return ;
}

void	append_array_to_stack(int *arr, int lenght, t_dlist **stack)
{
	int i = 0;

	while (i < lenght)
	{
		ft_append_next_stack(stack, ft_newnode_stack(arr[i]));
		i++;
	}
	return ;
}

int	main(void)
{
	t_dlist  *a = NULL;
	t_dlist  *b = NULL;
	int arr[] = {200, 2100, 2320, 0, -1299, 50};
	int lenght = sizeof(arr) / sizeof(*arr);
	int	i = 0;
	
	append_array_to_stack(arr, lenght, &a);
	ft_printf("Printing before move\n");
	ft_print_stacks(a, b);
	mov_push(&a, &b);
	mov_push(&a, &b);
	mov_push(&a, &b);
	mov_push(&a, &b);
	ft_printf("Printing after move\n");
	ft_print_stacks(a, b);
	return (0);
}
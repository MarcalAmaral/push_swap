/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:43:44 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/15 19:23:30 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"


/* Swap the first two elements of stack*/
void	mov_swap(t_stack **head)
{
	t_stack *node;
	t_stack *temp;

	if (!*head)
		return ;
	node = *head;
	if (node->next == NULL)
		return ;
	else {
		 /* Node->prev == NULL, node->next == 2nd element */
		 /* temp(2nd element)->prev == *head && temp->next == 3nd element */
		temp = node->next;
		temp->prev = NULL;
		node->prev = temp;
		node->next = temp->next;
		temp->next = node;
		*head = temp;
	}
}

/* Push top element of an stack to another */
void	move_push(t_push *src, t_push *dst)
{
	t_stack *node_src;
	t_stack *temp;
	t_stack *last;
	
	if (!src->head)
		return ;
	node_src = src->head;
	if (node_src->next == NULL)
	{
		src->head = NULL;
		src->tail = NULL;
		node_src->next = dst->head;
		if (dst->head->next)
			dst->head->prev = node_src;
		dst->head = node_src;
	}
	else if (node_src->next != NULL)
	{
		node_src->next->prev = NULL;
		dst->head = node_src;
		dst->tail = node_src;
		src->head = src->head->next;
		src->head->next = src->tail;
		last->next = temp;
	}
}

/* Rotate stack a */
void	move_ra(t_stack **head)
{
	
}

/* Rotate stack b */
void	move_rb(t_stack **head)
{
	
}

/* Rotate stack a & b */
void	move_rr(t_stack **head)
{

}

/* Reverse rotate a stack */
void	move_rra(t_stack **head)
{
	
}

/* Reverse rotate b stack */
void	move_rrb(t_stack **head)
{
	
}

/* Reverse rotate b & a stacks */
void	move_rrr(t_stack **head)
{
	
}
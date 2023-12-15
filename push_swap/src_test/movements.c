/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:43:44 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/15 17:57:07 by myokogaw         ###   ########.fr       */
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
void	move_push(t_stack **head, t_stack **tail)
{
	t_stack *node;
	t_stack *temp;
	
	if (!*head)
		return ;
	node = *head;
	if (node->next == NULL);
		return ;
	else {
		
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
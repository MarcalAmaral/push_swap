/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:43:44 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/16 18:07:56 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"


/* Swap the first two elements of stack*/
void	mov_swap(t_push *stack)
{
	t_stack *temp;
	t_stack *temp1;

	if (!stack->head)
		return ;
	temp = stack->head;
	if (!temp->next)
		return ;
	else
	{
		/* The first element turn 2nd element, prev == 2nd element, next == 3nd element*/
		/* The 2nd element turns 1nd element, prev == tail, next == 1nd element */
		/* Head == 2nd element, tail->next == head*/
		temp1 = temp->next;
		temp->next = temp1->next;
		temp->prev = temp1;
		temp1->next = temp;
		temp1->prev = stack->tail;
		stack->head = temp1;
		stack->tail->next = stack->head;
	}
}


/* Swap two stacks in the same time (ss) */
void	mov_ss(t_push *stack_a, t_push *stack_b)
{
	mov_swap(stack_a);
	mov_swap(stack_b);
	return ;
}

/*Considerations: Tail never change with 2 or more values, Head always change */
/* Push top element of an stack to another */
void	mov_push(t_push *src, t_push *dst)
{
	t_stack *temp;
	t_stack *temp1;

	/* Verifying if have a value in src stack */
	if (!src->head)
		return ;
	temp = src->head;
	/* Manipulate src stack */
	temp1 = temp->next;
	temp1->prev = src->tail;
	src->head = temp1;
	src->tail->next = src->head;
	/* Manipulate dst stack */
	if (!dst->head)
		dst->head = temp;
	temp->next = dst->head;
	dst->head = temp;
	if (!dst->tail)
		dst->tail = temp;
	temp->prev = dst->tail;
}

/* Rotate stack */
void	mov_rotate(t_push *stack)
{
	t_stack *temp;
	
	if (!stack->head)
		return ;
	temp = stack->head;
	stack->head = temp->next;
	temp->next = stack->head;
	stack->tail = temp;
}

/* Rotate stack a & b */
void	mov_rr(t_push *a, t_push *b)
{
	mov_rotate(a);
	mov_rotate(b);
}


/* The last value turn first*/
/* The first element turns 2nd element */
/* Tail equals prev */
/* Reverse rotate a stack */
void	mov_reverse(t_push *stack)
{
	t_stack *temp;
	
	if (!stack->head)
		return ;
	temp = stack->tail;
	stack->tail = temp->prev;
	temp->next = stack->head;
	stack->head = temp;
}

/* Reverse rotate b & a stacks */
void	mov_rrr(t_push *a, t_push *b)
{
	mov_reverse(a);
	mov_reverse(b);
}
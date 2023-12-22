/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:43:44 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/22 16:21:11 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"


/* Swap the first two elements of stack*/
void	mov_swap(t_stack *stack)
{
	int aux;

	if (!stack)
		return ;
	aux = stack->content;
	stack->content = stack->next->content;
	stack->next->content = aux;
}


/* Swap two stacks in the same time (ss) */
void	mov_ss(t_stack *stack_a, t_stack *stack_b)
{
	mov_swap(stack_a);
	mov_swap(stack_b);
	return ;
}

void	mov_push(t_stack *src, t_stack *dst)
{
	t_stack	*temp;

	if (!src)
		return ;
	temp = src;
	src = temp->next;
	src->prev = NULL;
	temp->next = dst;
	dst = temp;
}

/*Considerations: Tail never change with 2 or more values, Head always change */
/* Push top element of an stack to another */
// void	mov_push(t_push *src, t_push *dst)
// {
// 	t_stack *temp;
// 	t_stack *temp1;

// 	/* Verifying if have a value in src stack */
// 	if (!src->head)
// 		return ;
// 	temp = src->head;
// 	/* Manipulate src stack */
// 	temp1 = temp->next;
// 	temp1->prev = src->tail;
// 	src->head = temp1;
// 	src->tail->next = src->head;
// 	/* Manipulate dst stack */
// 	if (!dst->head)
// 		dst->head = temp;
// 	temp->next = dst->head;
// 	dst->head = temp;
// 	if (!dst->tail)
// 		dst->tail = temp;
// 	temp->prev = dst->tail;
// }


void	mov_rotate(t_stack *stack)
{
	t_stack *temp;

	if (!stack)
		return ;
	temp = 
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
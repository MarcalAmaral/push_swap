/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:52:59 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/21 17:03:43 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/* First becomes Second and Second becomes First */
/* What i need change? */
/* 1nd Node (Prev becomes second) (Next becomes 3) */
/* 2nd Node (Prev becomes last) (Next becomes first)*/
/* Por ser lista circular o next de last se altera, ele se começa apontar para o segundo nodo*/

void	swap(t_stack *firstNode)
{
	t_stack *secondNode;

	if (!firstNode)
		return ;
	secondNode = firstNode->next;
	firstNode->next = secondNode->next; /* 1nd->next, becomes 3nd */
	secondNode->prev = firstNode->prev; /* 2nd->prev, becomes last*/
	firstNode->prev = secondNode; /**/
	secondNode->next = firstNode;
	return ;
}

void	ss_swap(t_stack **stacks)
{
	swap(*(stacks));
	swap(*(stacks + 1));
	return ;
}


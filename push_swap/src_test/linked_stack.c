/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:53:06 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/13 16:58:38 by myokogaw         ###   ########.fr       */
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

void	ft_append_next_stack(t_stack **head, t_stack *node)
{
	t_stack	*temp;

	if (!node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	temp = ft_lstlast_stack(*head);
	temp->next = node;
	return ;
}

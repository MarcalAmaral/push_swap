/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:38:32 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/22 18:27:18 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist *ft_newnode_stack(int content)
{
	t_dlist *new;

	new = (t_dlist *) ft_calloc(1, sizeof(t_dlist));
	new->content = content;
	return (new);
}

void	ft_append_next_stack(t_dlist **head, t_dlist *node)
{
	t_dlist *temp;

	if (!node)
		return ;
	if (!*head)
	{
		node->next = node;
		node->prev = node;
		*head = node;
		return ;
	}
	(*head)->prev->next = node;
	node->next = *head;
	node->prev = (*head)->prev;
	(*head)->prev = node;
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:41:41 by codespace         #+#    #+#             */
/*   Updated: 2024/01/06 11:56:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist *ft_newnode_list(int content)
{
    t_dlist *node;

    node = (t_dlist *) ft_calloc(1, sizeof(t_dlist));
    node->content = content;
    return (node);
}

t_dlist	*ft_lstlast_dlist(t_dlist *list)
{
	while (list)
	{
		if (!list->next)
			return (list);
		list = list->next;
	}
	return (list);
}

void	ft_append_next_list(t_dlist **head, t_dlist *node)
{
	t_dlist	*temp;

	if (!node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	temp = ft_lstlast_dlist(*head);
	temp->next = node;
	return ;
}

void	ft_append_prev_list(t_dlist **head)
{
	t_dlist	*temp;
	t_dlist	*node;
	int		i;
	int		j;

	temp = *head;
	i = 0;
	if (i++ == 0)
		temp->prev = NULL;
	temp = temp->next;
	j = -1;
	while (temp)
	{
		node = *head;
		while (j++, j <= i - 1)
			if (i != 1)
				node = node->next;
		j = 0;
		temp->prev = node;
		i++;
		temp = temp->next;
	}
	return ;
}
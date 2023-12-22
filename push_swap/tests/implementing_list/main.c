/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:47:13 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/22 12:07:19 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/* Go implement a circular linked list */

t_dlist *ft_newnode_stack(int content)
{
	t_dlist *new;

	new = (t_dlist *) ft_calloc(1, sizeof(t_dlist));
	new->content = content;
	return (new);
}

t_dlist *ft_lstlast_stack(t_dlist *node)
{
	while (node)
	{
		if (node->next == NULL)
			break ;
		node = node->next;
	}
	return (node);
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

void	ft_free_list(t_dlist **head)
{
	t_dlist	*temp;
	t_dlist	*temp1;

	if (!*head)
		return ;
	temp = *head;
	while (temp)
	{
		temp1 = temp;
		if (temp->next == *head)
		{
			free(temp1);
			break ;
		}
		temp = temp->next;
		free(temp1);
	}
	free(head);
	return ;
}

t_dlist **init_stack(int *arr, int lenght)
{
	t_dlist **head;
	int		i;

	i = 0;
	head = (t_dlist **) ft_calloc(2, sizeof(t_dlist *));
	while (i < lenght)
	{
		ft_append_next_stack(head, ft_newnode_stack(arr[i]));
		i++;
	}
	return (head);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_dlist **head;
// 	t_dlist *temp;
// 	int arr[] = {20, 30, 11, 10, 0, 5};
// 	int i = sizeof(arr) / sizeof(*arr);
// 	int j = 0;

// 	// head = (t_dlist **) ft_calloc(1, sizeof(t_dlist **));
// 	// while (j < i)
// 	// {
// 	// 	ft_append_next_stack(head, ft_newnode_stack((void *) arr[j]));
// 	// 	j++;
// 	// }
// 	// temp = *head;
// 	// while (temp)
// 	// {
// 	// 	ft_printf("%d\n", temp->content);
// 	// 	if (temp->next == *head)
// 	// 		break ;
// 	// 	temp = temp->next;
// 	// }
// 	// ft_printf("Printing reverse list ========\n");
// 	// temp = (*head)->prev;
// 	// while (temp)
// 	// {
// 	// 	ft_printf("%d\n", temp->content);
// 	// 	if (temp->prev == (*head)->prev)
// 	// 		break ;
// 	// 	temp = temp->prev;
// 	// }
// 	ft_free_list(head);
// 	return (0);
// }
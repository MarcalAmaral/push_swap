/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:47:13 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/20 16:46:12 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_insertend_stack(t_stack **head, t_stack *new);
void	ft_print_stack(t_stack **head);
t_stack **array_to_list(int *arr, int lenght, t_stack **stacks);
t_stack *ft_newnode_stack(int content);

t_stack **init_stack(int *arr, int lenght)
{
	t_stack	**stacks;

	if (!arr)
		return (NULL);
	stacks = (t_stack **) ft_calloc(1, sizeof(t_stack **));
	array_to_list(arr, lenght, stacks);
	ft_print_stack(stacks);
	return (stacks);
}

void	ft_print_stack(t_stack **head)
{
	t_stack *temp;

	if (!*head)
		return ;
	temp = *head;
	while (temp)
	{
		ft_printf("%d\n", temp->content);
		if (temp->next == *head)
			break ;
		temp = temp->next;
	}
	ft_printf("Stack\n");
	return ;
}

t_stack **array_to_list(int *arr, int lenght, t_stack **stacks)
{
	int i;

	i = 0;
	while (i < lenght)
	{
		ft_insertend_stack(stacks, ft_newnode_stack(arr[i]));
		i++;
	}
	return (stacks);
}

t_stack *ft_newnode_stack(int content)
{
	t_stack *new;

	new = (t_stack *) ft_calloc(1, sizeof(t_stack));
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_insertend_stack(t_stack **head, t_stack *new)
{
	t_stack *last;
	t_stack *old_first;

	if (!new)
		return ;
	if (!*head)
	{
		new->next = new;
		new->prev = new;
		*head = new;
		return ;
	}
	old_first = (*head);
	last = (*head)->prev;
	new->next = old_first;
	old_first->prev = new;
	last->next = new;
}

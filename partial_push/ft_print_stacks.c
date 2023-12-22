/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:41:23 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/22 18:56:26 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*linked_lenght(t_dlist *a, t_dlist *b)
{
	t_dlist *temp;
	int		i = 0;
	int		j = 0;
	int		*ret;

	temp = a;
	while (temp)
	{
		i++;
		if (temp->next == a)
			break ;
		temp = temp->next;
	}
	temp = b;
	while (temp)
	{
		j++;
		if (temp->next == b)
			break ;
		temp = temp->next;
	}
	ret = (int *) ft_calloc(3, sizeof(int));
	ret[0] = i;
	ret[1] = j;
	return (ret);
}

void ft_print_stacks(t_dlist *a, t_dlist *b)
{
	t_dlist *temp;
	t_dlist *temp1;
	int		*ret;
	int		i = 0, j = 0;


	ret = linked_lenght(a, b);
	if (a && b)
	{
		temp = a;
		temp1 = b;
		ft_printf("Printing stacks\n====================================================\n");
		while (temp || temp1)
		{
			ft_printf("%d	%d\n", temp->content, temp1->content);
			if (i < ret[0])
			{
				temp = temp->next;
				i++;
			}
			if (j < ret[1])
			{
				temp = temp->next;
				j++;
			}
			if (i + 1 == ret[0] && j + 1 == ret[1])
				break ;
		}
		ft_printf("Stack A	Stack B\n");
		ft_printf("====================================================\n\n");
		return ;
	}
	if (a)
	{
		ft_printf("Printing stacks\n====================================================\n");
		temp = a;
		while (temp)
		{
			ft_printf("%d\n", temp->content);
			if (temp->next == a)
				break ;
			temp = temp->next;
		}
		ft_printf("Stack A	Stack B\n");
		ft_printf("====================================================\n\n");
		return ;
	}
	if (b)
	{
		ft_printf("Printing stacks\n====================================================\n");
		temp = b;
		while (temp)
		{
			ft_printf("	%d\n", temp->content);
			if (temp->next == b)
				break ;
			temp = temp->next;
		}
		ft_printf("Stack A	Stack B\n");
		ft_printf("====================================================\n\n");
		return ;
	}
	/* ft_printf("Printing reverse stack\n====================================================\n");
	temp = (*stacks)->prev;
	while (temp)
	{
		ft_printf("%d\n", temp->content);
		if (temp->prev == (*stacks)->prev)
			break ;
		temp = temp->prev;
	}
	ft_printf("====================================================\n"); */
	return ;
}
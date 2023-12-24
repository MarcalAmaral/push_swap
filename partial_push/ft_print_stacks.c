/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:41:23 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/23 15:10:39 by marvin           ###   ########.fr       */
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
		{
			if (j == 1)
				j++;
			break ;
		}
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
	int		i = 0;
	int		j = 0;
	int		k = 0;
	int		max;
	int		*lenght;

	lenght = linked_lenght(a, b);
	if (lenght[0] > lenght[1])
		max = lenght[0];
	else
		max = lenght[1]; 
	if (a && b)
	{
		temp = a;
		temp1 = b;
		ft_printf("Printing stacks\n====================================================\n");
		while (k < max)
		{
			if (j < lenght[0])
			{
				ft_printf("%d", temp->content);
				temp = temp->next;
				j++;
			}
			if (i < lenght[1])
			{
				ft_printf("	%d", temp1->content);
				temp1 = temp1->next;
				i++;
			}
			ft_printf("\n");
			k++;
			// else
			// {
			// 	ft_printf("%d	%d", temp->content, temp1->content)
			// 	temp = temp->next;
			// 	temp1 = temp1->next;
			// }
			// ft_printf("\n");
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:21:21 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/22 12:21:37 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_dlist **head)
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
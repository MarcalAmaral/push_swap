/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:58:06 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/13 16:55:33 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_stack **create_stacks(int *arr, int lenght)
{
	int		i;
	t_stack	**head;

	i = 0;
	while (i < lenght)
	{
		ft_append_next_stack(head, ft_newnode_stack(arr[i]));
		i++;
	}
	return (head);
}
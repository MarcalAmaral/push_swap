/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:48:20 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/22 18:42:42 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mov_swap(t_dlist *firstNode)
{
	int temp;

	if (!firstNode)
		return ;
	if (!firstNode->next)
		return ;
	else
	{
		temp = firstNode->content;
		firstNode->content = firstNode->next->content;
		firstNode->next->content = temp;
	}
}

// void	move_ss(t_dlist **stacks)
// {
		
// }

void	mov_push(t_dlist **src, t_dlist **dest)
{
	t_dlist *temp;
	t_dlist *f_src;
	t_dlist *f_dst;

	if (!*src)
		return ;
	f_src = *src;
	if (!*dest)
	{
		temp = f_src;	
		f_src->prev->next = temp->next;
		f_src = temp->next;
		f_src->prev = temp->prev;
		temp->next = temp;
		temp->prev = temp;
		*dest = temp;
		return ;
	}
	temp = f_src;
	f_dst = *dest;
	f_src = temp->next;
	f_src->prev->next = f_src;
	temp->next = f_dst;
	temp->prev = f_dst->prev;
	f_dst = temp;
}

int	main(void)
{
	t_dlist  *a = NULL;
	t_dlist  *b = NULL;
	int arr[] = {200, 2100, 2320, 0, -1299, 50};
	int lenght = sizeof(arr) / sizeof(*arr);
	int	i = 0;
	
	while (i < lenght)
	{
		ft_append_next_stack(&a, ft_newnode_stack(arr[i]));
		i++;
	}
	ft_printf("Printing before move\n");
	ft_print_stacks(a, b);
	mov_push(&a, &b);
	ft_print_stacks(a, b);
	return (0);
}
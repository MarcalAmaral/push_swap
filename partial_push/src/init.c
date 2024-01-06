/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:27:46 by myokogaw          #+#    #+#             */
/*   Updated: 2024/01/06 12:08:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_stack(int *arr, int lenght, t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->a = (t_dlist **) ft_calloc(1, sizeof(t_dlist *));
	stacks->b = (t_dlist **) ft_calloc(1, sizeof(t_dlist *));
	while (i < lenght)
	{
		ft_append_next_list(stacks->a, ft_newnode_list(arr[i]));
		i++;
	}
	ft_append_prev_list(stacks->a);
	return ;
}

// void	init1(int argc, char **argv)
// {
// 	t_stacks stacks;
// 	int		i;
// 	char	**args;
// 	int 	*arr;

// 	args = ft_split(argv[0], ' ');
// 	if (invalid_param(args))
// 		err_msg(INVPARAMS);
// 	if (bigger_or_smaller_int(args))
// 		err_msg(BIGSMLINT);
// 	i = matrix_lenght((void **) args);
// 	arr = (int *) ft_calloc(i + 1, sizeof(int));
// 	arr[i] = 0;
// 	while (--i >= 0)
// 		arr[i] = ft_atoi(args[i]);
// 	if (duplicated_values(arr, matrix_lenght((void **) args)) == 1)
// 	{
// 		ft_free_matrix((void **) args);
// 		free(arr);
// 		err_msg(ERRDUPVALUES);
// 	}
// 	init_stack(arr, matrix_lenght((void **) args), &stacks);
// 	ft_print_stacks(&stacks);
// 	ft_free_matrix((void **) args);
// 	ft_free_stack(stacks);
// 	free(arr);
// 	return ;
// }

// void	init2(int argc, char **argv)
// {
// 	t_stacks stacks;
// 	int *arr;
// 	int	i;

// 	if (invalid_param(argv))
// 		err_msg(INVPARAMS);
// 	if (bigger_or_smaller_int(argv))
// 		err_msg(BIGSMLINT);
// 	i = matrix_lenght((void **) argv);
// 	arr = (int *) ft_calloc(i + 1, sizeof(int));
// 	arr[i] = 0;
// 	while (--i >= 0)
// 		arr[i] = ft_atoi(argv[i]);
// 	if (duplicated_values(arr, matrix_lenght((void **) argv)) == 1)
// 	{
// 		free(arr);
// 		err_msg(ERRDUPVALUES);
// 	}
// 	init_stack(arr, matrix_lenght((void **) argv), ¨&stacks);
// 	ft_print_stacks(&stacks);
// 	ft_free_stack(stacks);
// 	free(arr);
// 	return ;
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:27:46 by myokogaw          #+#    #+#             */
/*   Updated: 2024/01/09 19:13:00 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

int	first_validations(char **args)
{
	if (invalid_param(args))
		return(INVPARAMS);
	if (bigger_or_smaller_int(args))
		return(BIGSMLINT);
	return (0);
}

int *formated_array(char **argv, int argc)
{
	char **args;
	int	i;
	int	*arr;

	if (argc == 1)
		args = ft_split(argv[0], ' ');
	else
		args = argv;
	err_msg(first_validations(argv));
	i = ft_matrix_lenght((void **) args);
	arr = (int *) ft_calloc(i + 1, sizeof(int));
	arr[i] = 0;
	while (--i >= 0)
		arr[i] = ft_atoi(args[i]);
	if (duplicated_values(arr, argc) == 1)
	{
		if (argc == 1)
			ft_free_matrix((void **) args);		
		free(arr);
		err_msg(ERRDUPVALUES);	
	}
	if (argc == 1)
		ft_free_matrix((void **) args);
	return (arr);
}


void	init_str(char **argv)
{
	t_stacks stacks;
	int 	*arr;

	arr = formated_array(argv, 1);
	init_stack(arr, 5, &stacks);
	ft_print_stacks(*stacks.a, *stacks.b);
	return ;
}

void	init_mult_str(int argc, char **argv)
{
	t_stacks stacks;
	int *arr;

	arr = formated_array(argv, argc);
	init_stack(arr, argc, &stacks);
	ft_print_stacks(*stacks.a, *stacks.b);
	return ;
}

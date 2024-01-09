/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:27:46 by myokogaw          #+#    #+#             */
/*   Updated: 2024/01/09 12:28:00 by myokogaw         ###   ########.fr       */
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

int	validations(char **args)
{
	if (invalid_param(args))
		return(INVPARAMS);
	if (bigger_or_smaller_int(args))
		return(BIGSMLINT);
}

int *formated_array(char **argv, int type_init)
{
	char **args;
	int	i;
	int	lenght;
	int	*arr;

	if (type_init == 0)
		args = ft_split(argv[0], ' ');
	else
		args = argv;
	i = matrix_lenght((void **) args);
	arr = (int *) ft_calloc(i + 1, sizeof(int));
	arr[i] = 0;
	while (--i >= 0)
		arr[i] = ft_atoi(args[i]);
	if (duplicated_values(arr, ft_matrix_lenght((void **) args)) == 1)
	{
		if (type_init == 0)
			ft_free_matrix((void **) args);		
		free(arr);
		err_msg(ERRDUPVALUES);	
	}
	if (type_init == 0)
		ft_free_matrix(args);
	return (arr);
}

void	init_str(int argc, char **argv)
{
	t_stacks stacks;
	int		i;
	char	**args;
	int 	*arr;

	i = 0;
	i = first_validations(args);
	if (i != 0)
		err_msg(i);
	arr = formated_array(args, 0);
	init_stack(arr, ft_matrix_lenght((void **) args), &stacks);
	return ;
}

void	init_mult_str(int argc, char **argv)
{
	t_stacks stacks;
	int *arr;
	int	i;

	i = 0;
	i = first_validations(argv);
	if (i != 0)
		err_msg(i);
	formated_array(argv, 1);
	init_stack(arr, ft_matrix_lenght((void **) argv), &stacks);
	return ;
}

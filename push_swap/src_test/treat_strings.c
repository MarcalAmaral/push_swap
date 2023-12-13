/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:41:13 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/13 16:55:56 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	*convert_str_arr(char *str)
{	
	int		*arr;
	char	**matrix;

	matrix = ft_split(str, ' ');
	arr = ret_arr(matrix);
	return (arr);
}

int *convert_args_arr(char **argv)
{
	int		*arr;
	t_stack	**head;

	ft_print_matrix_str((void **) argv);
	head = ret_arr_from_argv(argv);
	ft_print_matrix_int(arr);
	return (arr);
}

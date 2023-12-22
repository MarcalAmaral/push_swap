/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:41:13 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/16 18:00:42 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	*ret_arr(char **matrix)
{
	int	lenght;
	int *arr;
	int i;

	lenght = matrix_lenght((void **) matrix);
	arr = (int *) ft_calloc(lenght + 1, sizeof(int));
	arr[lenght] = 0;
	i = 0;
	while (i < lenght)
	{
		arr[i] = ft_atoi(matrix[i]);
		i++;
	}
	return (arr);
}

int	*ret_arr_from_argv(char **argv)
{
	int	lenght;
	int *arr;
	int i;

	argv++;
	lenght = matrix_lenght((void **) argv);
	arr = (int *) ft_calloc(lenght + 1, sizeof(int));
	arr[lenght] = 0;
	i = 0;
	while (i < lenght)
	{
		arr[i] = ft_atoi(argv[i]);
		i++;
	}
	return (arr);
}

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

	arr = ret_arr_from_argv(argv);
	return (arr);
}

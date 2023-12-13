/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:45:13 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/13 16:57:08 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_free_matrix(void **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return ;
}

void	ft_print_matrix_str(void **matrix)
{
	int i = 0;

	printf("----------------str matrix----------------\n");
	while (matrix[i])
	{
		printf("value of matrix[%d]: %s\n", i, (char *) matrix[i]);
		i++;
	}
}
void	ft_print_matrix_int(int *arr)
{
	int i = 0;

	printf("----------------int matrix----------------\n");
	while (arr[i])
	{
		printf("value of matrix[%d]: %i\n", i, arr[i]);
		i++;
	}
}

int	matrix_lenght(void **matrix)
{
	int i = 0;

	while (matrix[i])
		i++;
	return (i);
}

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

	lenght = matrix_lenght((void **) argv);
	arr = (int *) ft_calloc(lenght, sizeof(int));
	arr[lenght] = 0;
	i = 0;
	while (i < lenght - 1)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (arr);
}

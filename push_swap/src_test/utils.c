/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:45:13 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/16 17:41:37 by myokogaw         ###   ########.fr       */
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

int	matrix_int_lenght(int *arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
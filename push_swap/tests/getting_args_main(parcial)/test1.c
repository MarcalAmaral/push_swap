/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:11:55 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/20 16:26:44 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/* Testando o recebimento dos valores da main (argc < 2) (argc == 2 && 2nd elem == string) */
/* (argc > 2) */

void	printing_result(int *arr, char *str)
{
	int	i = 0;

	ft_printf("%s\n", str);
	while (arr[i])
	{
		ft_printf("%d ", arr[i]);
		i++;
	}
	ft_printf("\n");
	return ;
}

void	ft_free_matrix(void **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	matrix_lenght(void **matrix)
{
	int i = 0;

	while (matrix[i])
		i++;
	return (i);
}

int	invalid_num_of_args(void)
{
	ft_putstr_fd("Error\n- Invalid num of args, pass one or more int values\n", 2);
	return (1);
}
void	init1(int argc, char **argv)
{
	int		i;
	char	**args;
	int 	*arr;

	args = ft_split(argv[1], ' ');
	i = matrix_lenght((void **) args);
	arr = (int *) ft_calloc(i + 1, sizeof(int));
	arr[i] = 0;
	while (--i >= 0)
		arr[i] = ft_atoi(args[i]);
	printing_result(arr, "init 1");
	free(arr);
	ft_free_matrix((void **) args);
	return ;
}

void	init2(int argc, char **argv)
{
	int *arr;
	int	i;

	i = matrix_lenght((void **) argv);
	arr = (int *) ft_calloc(i + 1, sizeof(int));
	arr[i] = 0;
	while (--i >= 0)
		arr[i] = ft_atoi(argv[i]);
	printing_result(arr, "init 2");
	free(arr);
	return ;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (invalid_num_of_args());
	else if (argc == 2 && argv[1])
		init1(argc, argv);
	else
		init2(argc - 1, &argv[1]);
	return (0);
}

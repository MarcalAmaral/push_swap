/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   body.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:33:33 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/18 19:17:35 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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

void	init1(int argc, char **argv)
{
	int		i;
	char	**args;
	int 	*arr;

	args = ft_split(argv[0], ' ');
	if (invalid_param(args))
		err_msg(INVPARAMS);
	if (bigger_or_smaller_int(args))
		err_msg(BIGSMLINT);
	i = matrix_lenght((void **) args);
	arr = (int *) ft_calloc(i + 1, sizeof(int));
	arr[i] = 0;
	while (--i >= 0)
		arr[i] = ft_atoi(args[i]);
	if (duplicated_values(arr) == 1)
	{
		ft_free_matrix((void **) args);
		free(arr);
		err_msg(ERRDUPVALUES);
	}
	ft_free_matrix((void **) args);
	return ;
}

void	init2(int argc, char **argv)
{
	int *arr;
	int	i;

	if (invalid_param(argv))
		err_msg(INVPARAMS);
	if (bigger_or_smaller_int(argv))
		err_msg(BIGSMLINT);
	i = matrix_lenght((void **) argv);
	arr = (int *) ft_calloc(i + 1, sizeof(int));
	arr[i] = 0;
	while (--i >= 0)
		arr[i] = ft_atoi(argv[i]);
	if (duplicated_values(arr) == 1)
	{
		free(arr);
		err_msg(ERRDUPVALUES);
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		err_msg(INVNUMARGS);
	else if (argc == 2 && argv[1])
		init1(argc, &argv[1]);
	else
		init2(argc - 1, &argv[1]);
	return (0);
}

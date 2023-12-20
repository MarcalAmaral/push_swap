/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prev.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:33:33 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/20 16:51:11 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/* Validar os input. Não devemos possuir valores inteiros repetidos */
/* valores maiores que inteiros e argumentos que não sejam números inteiros */

long int	ft_atoli(char *nptr)
{
	long int	signal;
	long int	result;

	signal = 1;
	result = 0;
	while (((*nptr >= 9) && (*nptr <= 13)) || *nptr == 32)
		nptr++;
	if ((*nptr == 45) || (*nptr == 43))
	{
		if (*nptr == 45)
			signal *= -1;
		nptr++;
	}
	while ((*nptr >= 48) && (*nptr <= 57))
	{
		result *= 10;
		result += *nptr - 48;
		nptr++;
	}
	return (result * signal);
}

void	err_msg(int err)
{
	if (err == INVNUMARGS)
	{
		ft_putstr_fd("Error\n- Invalid num of args, pass one or more int values\n", STDERR_FILENO);
		exit(INVNUMARGS);
	}
	if (err == ERRDUPVALUES)
	{
		ft_putstr_fd("Error\n- Duplicated values\n", STDERR_FILENO);
		exit(ERRDUPVALUES);
	}
	if (err == INVPARAMS)
	{
		ft_putstr_fd("Error\n- Invalid params, pass just numbers\n", STDERR_FILENO);
		exit(INVPARAMS);
	}
	if (err == BIGSMLINT)
	{
		ft_putstr_fd("Error\n- Just pass int values, bigger or smaller is not accept.\n", STDERR_FILENO);
		exit(BIGSMLINT);
	}
}

int	bigger_or_smaller_int(char **argv)
{
	int i;
	int j;
	long int n;

	i = 0;
	while (argv[i])
	{
		n = ft_atoli(argv[i]);
		if (n > INTMAX || n < INTMIN)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
int	is_valid_c(char c)
{
	if (ft_isdigit(c) == 0 && c != ' ' 
	& c != '-' && c != '+' && c != '\t')
		return (TRUE);
	return (FALSE);
}

int	find_invalid_c(char **argv)
{
	int	i;
	int j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (is_valid_c(argv[i][j]))
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

int	invalid_param(char **argv)
{
	int i;
	int j;
	
	i = 0;
	if (find_invalid_c(argv))
		return (TRUE);
	while (argv[i])
	{
		if (ft_strncmp(argv[i], "0", 1) != 0)
		{
			if (ft_atoi(argv[i]) == 0)
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

int	duplicated_values(int *arr, int lenght)
{
	int	i;
	int j;

	i = 0;
	while (i < lenght)
	{
		j = i + 1;
		while (j < lenght)
		{
			if (arr[i] == arr[j])
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
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

void	init1(int argc, char **argv)
{
	t_stack **stacks;
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
	if (duplicated_values(arr, matrix_lenght((void **) argv)) == 1)
	{
		ft_free_matrix((void **) args);
		free(arr);
		err_msg(ERRDUPVALUES);
	}
	ft_free_matrix((void **) args);
	stacks = init_stack(arr, matrix_lenght((void **) argv));
	return ;
}

void	init2(int argc, char **argv)
{
	t_stack **stacks;
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
	if (duplicated_values(arr, matrix_lenght((void **) argv)) == 1)
	{
		free(arr);
		err_msg(ERRDUPVALUES);
	}
	stacks = init_stack(arr, matrix_lenght((void **) argv));
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

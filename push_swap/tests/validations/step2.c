/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:28:34 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/18 19:23:50 by myokogaw         ###   ########.fr       */
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

int	duplicated_values(int *arr)
{
	int	i;
	int j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (arr[i] == arr[j])
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

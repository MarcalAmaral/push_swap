/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:26:39 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/22 12:37:41 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (ft_is_valid_c(argv[i][j]))
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
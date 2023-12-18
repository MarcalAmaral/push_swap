/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:00:19 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/18 15:28:00 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init1(int argc, char **argv)
{
	int		i;
	char	**args;
	int 	*arr;

	args = ft_split(argv[1], ' ');
	i = ft_matrix_lenght((void **) args);
	arr = (int *) ft_calloc(i + 1, sizeof(int));
	arr[i] = 0;
	while (--i)
		arr[i] = ft_atoi(args[i]);
	ft_free_matrix((void **) args);
	return ;
}

void	init2(int argc, char **argv)
{
	int *arr;
	int	i;

	i = ft_matrix_lenght((void **) argv);
	arr = (int *) ft_calloc(i + 1, sizeof(int));
	arr[i] = 0;
	while (--i)
		arr[i] = ft_atoi(argv[i]);
	return ;
}
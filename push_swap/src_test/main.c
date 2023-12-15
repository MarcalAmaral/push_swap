/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:38:44 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/15 15:23:13 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	int *arr;

	if (argc < 2)
		ft_putstr_fd("Error\n - Invalid num of args, pass one or more arguments\n", 2);
	if (argc == 2 && argv[1])
		arr = convert_str_arr(argv[1]);
	if (argc > 2)
		arr = convert_args_arr(argv);
	return (0);
}

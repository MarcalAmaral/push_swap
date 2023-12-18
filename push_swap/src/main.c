/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:55:43 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/18 15:01:43 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

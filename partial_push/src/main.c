/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:25:42 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/22 18:27:16 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

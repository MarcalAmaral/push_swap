/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:25:42 by myokogaw          #+#    #+#             */
/*   Updated: 2024/01/09 19:11:13 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		err_msg(INVNUMARGS);
	else if (argc == 2 && argv[1])
		init_str((char **) &argv[1]);
	else
		init_mult_str(argc - 1, (char **) &argv[1]);
	return (0);
}

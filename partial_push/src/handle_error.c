/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:25:04 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/22 12:25:12 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

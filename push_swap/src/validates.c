/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:56:52 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/18 14:58:47 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	invalid_num_of_args(void)
{
	ft_putstr_fd("Error\n- Invalid num of args, pass one or more int values\n", 2);
	return (1);
}
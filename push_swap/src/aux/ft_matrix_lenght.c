/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_lenght.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:05:42 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/18 15:27:08 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_matrix_lenght(void **matrix)
{
	int i = 0;

	while (matrix[i])
		i++;
	return (i);
}

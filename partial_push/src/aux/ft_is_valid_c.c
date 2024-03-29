/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:31:47 by myokogaw          #+#    #+#             */
/*   Updated: 2024/01/09 15:53:39 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_valid_c(char c)
{
	if (ft_isdigit(c) == 0 && (c != ' ')
		& (c != '-') && (c != '+') && (c != '\t'))
		return (TRUE);
	return (FALSE);
}

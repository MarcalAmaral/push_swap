/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:35:18 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/18 16:41:03 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../lib/libft/inc/libft.h"

# define TRUE 1
# define FALSE 0
# define ERRDUPVALUES 2
# define INVPARAMS 3
# define INVNUMARGS 4
# define BIGSMLINT 5
# define INTMAX 2147483647
# define INTMIN -2147483648

typedef struct s_stack {
	int content;
	struct s_stack *next;
	struct s_stack *prev;
}	t_stack;

/* error messsages */
void	err_msg(int err);

/* check if have a duplicated values */
int		duplicated_values(int *arr);

/* check if receive a non number in param */
int		invalid_param(char **argv);

/* check if receive a value bigger ou smaller a integer (4 bytes) */
int		bigger_or_smaller_int(char **argv);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:02:39 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/20 16:45:19 by myokogaw         ###   ########.fr       */
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

t_stack **init_stack(int *arr, int lenght);

#endif
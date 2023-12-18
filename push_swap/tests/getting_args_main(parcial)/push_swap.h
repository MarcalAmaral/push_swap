/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:35:18 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/18 15:12:29 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../lib/libft/inc/libft.h"

typedef struct s_stack {
	int content;
	struct s_stack *next;
	struct s_stack *prev;
}	t_stack;


/* Validations */
int	invalid_num_of_args(void);


/* Auxiliar functions */
int	matrix_lenght(void **matrix);

#endif
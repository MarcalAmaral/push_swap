/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:47:40 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/13 16:55:31 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/inc/libft.h"

/* Printf */
# include <stdio.h>

typedef struct s_stack {
	int content;
	struct s_stack *next;		
} t_stack;

void	ft_print_matrix_str(void **matrix);
void	ft_print_matrix_int(int *arr);

/* Convert matrix with atoi */
int		*ret_arr(char **matrix);
int		*convert_str_arr(char *str);
int		*ret_arr_from_argv(char **argv);
int		*convert_args_arr(char **argv);

/* Matrix ops */
int		matrix_lenght(void **matrix);

/* Create a stacks */
t_stack **create_stacks(int *arr, int lenght);

#endif

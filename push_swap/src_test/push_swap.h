/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:47:40 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/18 14:40:57 by myokogaw         ###   ########.fr       */
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
	struct s_stack *prev;
} t_stack;

void	ft_print_matrix_str(void **matrix);
void	ft_print_matrix_int(int *arr);

/* Convert matrix with atoi */
int		*ret_arr(char **matrix);
int		*convert_str_arr(char *str);
int		*ret_arr_from_argv(char **argv);
int 	*convert_args_arr(char **argv);

/* Matrix ops */
int		matrix_lenght(void **matrix);
int		matrix_int_lenght(int *arr);

/* Movements */
void	mov_swap(t_push *stack);
void	mov_push(t_push *stack_src, t_push *stack_dst);
void	mov_ss(t_push *stack_a, t_push *stack_b);
void	mov_rotate(t_push *stack);
void	mov_rr(t_push *a, t_push *b);
void	mov_reverse(t_push *stack);
void	mov_rrr(t_push *a, t_push *b);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:21:55 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/27 15:01:26 by marvin           ###   ########.fr       */
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

typedef struct s_stacks {
	t_list **a;
	t_list **b;
} t_stacks;

/* Auxiliar functions */
long int	ft_atoli(char *nptr);
void		ft_free_matrix(void **matrix);
void		ft_free_stack(t_dlist **head);
int			matrix_lenght(void **matrix);
int			ft_is_valid_c(char c);

/* Message error */
void		err_msg(int err);

/* Initialize stacks */
void		init1(int argc, char **argv);
void		init2(int argc, char **argv);

/* Linked list */
void		ft_append_next_stack(t_dlist **head, t_dlist *node);
t_dlist 	*ft_newnode_stack(int content);

/* Validate functions */
int			bigger_or_smaller_int(char **argv);
int			find_invalid_c(char **argv);
int			invalid_param(char **argv);
int			duplicated_values(int *arr, int lenght);

/* Init stack */
void 		init_stack(int *arr, int lenght, t_stacks *stacks);

/* Extra functions */
void		ft_print_stacks(t_list *a, t_list *b);

#endif
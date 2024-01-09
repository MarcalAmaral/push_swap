/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:21:55 by myokogaw          #+#    #+#             */
/*   Updated: 2024/01/09 16:59:55 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/inc/libft.h"

# define TRUE 1
# define FALSE 0
# define ERRDUPVALUES 2
# define INVPARAMS 3
# define INVNUMARGS 4
# define BIGSMLINT 5
# define INTMAX 2147483647
# define INTMIN -2147483648

#ifdef __cplusplus
	extern "C" {
#endif

typedef struct s_stacks {
	t_dlist **a;
	t_dlist **b;
} t_stacks;

/* Auxiliar functions */
long int	ft_atoli(char *nptr);
void		ft_free_matrix(void **matrix);
void		ft_free_stack(t_dlist **head);
int			ft_matrix_lenght(void **matrix);
int			ft_is_valid_c(char c);

/* Message error */
void		err_msg(int err);

/* Initialize stacks */
void		init_str(int argc, char **argv);
void		init_mult_str(int argc, char **argv);

/* Linked list */
t_dlist *ft_newnode_list(int content);
t_dlist	*ft_lstlast_dlist(t_dlist *list);
void	ft_append_next_list(t_dlist **head, t_dlist *node);
void	ft_append_prev_list(t_dlist **head);

/* Validate functions */
int			bigger_or_smaller_int(char **argv);
int			find_invalid_c(char **argv);
int			invalid_param(char **argv);
int			duplicated_values(int *arr, int lenght);

/* Init stack */
void 		init_stack(int *arr, int lenght, t_stacks *stacks);

/* Extra functions */
void		ft_print_stacks(t_dlist *a, t_dlist *b);

#ifdef __cplusplus
	}
#endif

#endif
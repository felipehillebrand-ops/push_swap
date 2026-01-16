/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:55:45 by fjose-hi          #+#    #+#             */
/*   Updated: 2026/01/15 20:51:29 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "Libft/libft.h"
# include "Libft/get_next_line.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

/* Initialization */
void	assign_index(t_stack *stack);
t_stack	*init_stack(int ac, char **av);

/* Checklist & Checklist Utils */
void	parse_init(int ac, char **av);
int		ft_issign(int c);
long	ft_atol(const char *str);
void	free_arg(char **args);
void	error_exit(void);

/* Sorting Algorithms */
int		is_sorted(t_stack *stack);
void	sort_method(t_stack **stack_a, t_stack **stack_b, int stack_size);
int		find_lowest_index(t_stack *stack);
int		find_highest_index(t_stack *stack);
int		find_position(t_stack *stack, int target_index);

/* Sorting Method */
void	sort_3(t_stack **stack);
void	sort_4_or_5(t_stack **stack_a, t_stack **stack_b);
void	chunk_sort(t_stack **stack_a, t_stack **stack_b);
void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b, int chunk_size);
void	push_back_to_a(t_stack **stack_a, t_stack **stack_b);

/* Moves */
void	do_sa(t_stack **stack_a, int print);
void	do_sb(t_stack **stack_b, int print);
void	do_ss(t_stack **stack_a, t_stack **stack_b, int print);
void	do_pa(t_stack **stack_a, t_stack **stack_b, int print);
void	do_pb(t_stack **stack_a, t_stack **stack_b, int print);
void	do_ra(t_stack **stack_a, int print);
void	do_rb(t_stack **stack_b, int print);
void	do_rr(t_stack **stack_a, t_stack **stack_b, int print);
void	do_rra(t_stack **stack_a, int print);
void	do_rrb(t_stack **stack_b, int print);
void	do_rrr(t_stack **stack_a, t_stack **stack_b, int print);

/* Stack Functions */
t_stack	*ft_newnode(int value);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stackbeforelast(t_stack *stack);
int		ft_stacksize(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_free_stack(t_stack **stack);
int		ft_find_first_in_chunk(t_stack *stack, int start, int end);

#endif

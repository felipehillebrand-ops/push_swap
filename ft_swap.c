/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:46:23 by fjose-hi          #+#    #+#             */
/*   Updated: 2026/01/03 17:28:01 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	do_sa(t_stack **stack_a)
{
	ft_swap(*stack_a);
	write(1, "sa\n", 3);
}

void	do_sb(t_stack **stack_b)
{
	ft_swap(*stack_b);
	write(1, "sb\n", 3);
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(*stack_a);
	ft_swap(*stack_b);
	write(1, "ss\n", 3);
}

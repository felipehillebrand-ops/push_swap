/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:40:04 by fjose-hi          #+#    #+#             */
/*   Updated: 2026/01/15 21:01:45 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	a = (*stack)->index;
	b = (*stack)->next->index;
	c = (*stack)->next->next->index;
	if (a > b && b > c)
	{
		do_sa(stack, 1);
		do_rra(stack, 1);
	}
	else if (a > c && c > b)
		do_ra(stack, 1);
	else if (b > a && a > c)
		do_rra(stack, 1);
	else if (b > c && c > a)
	{
		do_sa(stack, 1);
		do_ra(stack, 1);
	}
	else if (c > a && a > b)
		do_sa(stack, 1);
}

static void	lowest_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	lowest;
	int	pos;
	int	size;
	int	rra_count;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	lowest = find_lowest_index(*stack_a);
	pos = find_position(*stack_a, lowest);
	size = ft_stacksize(*stack_a);
	if (pos <= size / 2)
		while (pos-- > 0)
			do_ra(stack_a, 1);
	else
	{
		rra_count = size - pos;
		while (rra_count-- > 0)
			do_rra(stack_a, 1);
	}
	do_pb(stack_a, stack_b, 1);
}

void	sort_4_or_5(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a || !stack_b)
		return ;
	while (ft_stacksize(*stack_a) > 3)
		lowest_to_b(stack_a, stack_b);
	sort_3(stack_a);
	if (ft_stacksize(*stack_b) == 2
		&& (*stack_b)->index < (*stack_b)->next->index)
		do_sb(stack_b, 1);
	while (*stack_b)
		do_pa(stack_a, stack_b, 1);
}

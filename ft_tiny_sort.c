/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:40:04 by fjose-hi          #+#    #+#             */
/*   Updated: 2026/01/07 21:29:41 by fjose-hi         ###   ########.fr       */
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
		do_sa(stack);
		do_rra(stack);
	}
	else if (a > c && c > b)
		do_ra(stack);
	else if (b > a && a > c)
		do_rra(stack);
	else if (b > c && c > a)
	{
		do_sa(stack);
		do_ra(stack);
	}
	else if (c > a && a > b)
		do_sa(stack);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	lowest;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	lowest = find_lowest_index(*stack_a);
	if ((*stack_a)->index == lowest)
		;
	else if ((*stack_a)->next->index == lowest)
		do_sa(stack_a);
	else if ((*stack_a)->next->next->index == lowest)
	{
		do_ra(stack_a);
		do_ra(stack_a);
	}
	else if ((*stack_a)->next->next->next->index == lowest)
		do_rra(stack_a);
	do_pb(stack_a, stack_b);
	sort_3(stack_a);
	do_pa(stack_a, stack_b);
}

static void	lowest_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	lowest;
	int	pos;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	lowest = find_lowest_index(*stack_a);
	pos = find_position(*stack_a, lowest);
	if (pos == 0)
		;
	else if (pos == 1)
		do_sa(stack_a);
	else if (pos == 2)
	{
		do_ra(stack_a);
		do_ra(stack_a);
	}
	else if (pos == 3)
	{
		do_rra(stack_a);
		do_rra(stack_a);
	}
	else if (pos == 4)
		do_rra(stack_a);
	do_pb(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a || !stack_b)
		return ;
	while (ft_stacksize(*stack_a) > 3)
		lowest_to_b(stack_a, stack_b);
	sort_3(stack_a);
	if ((*stack_b)->index < (*stack_b)->next->index)
		do_sb(stack_b);
	do_pa(stack_a, stack_b);
	do_pa(stack_a, stack_b);
}

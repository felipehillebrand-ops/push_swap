/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:40:04 by fjose-hi          #+#    #+#             */
/*   Updated: 2026/01/09 17:50:38 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack)
{
	int	highest_pos;

	if (is_sorted(*stack))
		return ;
	highest_pos = find_position(*stack, find_highest_index(*stack));
	if (highest_pos == 0)
		do_ra(stack);
	else if (highest_pos == 1)
		do_rra(stack);
	if ((*stack)->content > (*stack)->next->content)
		do_sa(stack);
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
			do_ra(stack_a);
	else
	{
		rra_count = size - pos;
		while (rra_count-- > 0)
			do_rra(stack_a);
	}
	do_pb(stack_a, stack_b);
}

void	sort_4_or_5(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a || !stack_b)
		return ;
	while (ft_stacksize(*stack_a) > 3)
		lowest_to_b(stack_a, stack_b);
	sort_3(stack_a);
	if (ft_stacksize(*stack_b) == 2
		&& (*stack_b)->content < (*stack_b)->next->content)
		do_sb(stack_b);
	while (*stack_b)
		do_pa(stack_a, stack_b);
}

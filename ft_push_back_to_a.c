/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back_to_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:23:51 by fjose-hi          #+#    #+#             */
/*   Updated: 2026/01/12 21:15:33 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_closer(int pos_next, int pos_max, int size)
{
	int	cost_max;
	int	cost_next;

	if (pos_max <= size / 2)
		cost_max = pos_max;
	else
		cost_max = size - pos_max;
	if (pos_next <= size / 2)
		cost_next = pos_next;
	else
		cost_next = size - pos_next;
	return (cost_next < cost_max);
}

static void	move_to_top_b(t_stack **stack_b, int pos)
{
	int	size;

	size = ft_stacksize(*stack_b);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			do_rb(stack_b);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			do_rrb(stack_b);
			pos++;
		}
	}
}

static void	push_max_to_a(t_stack **stack_a, t_stack **stack_b, int max_idx)
{
	int	size_b;
	int	pos_max;
	int	pos_next;

	size_b = ft_stacksize(*stack_b);
	pos_max = find_position(*stack_b, max_idx);
	if (size_b > 1)
		pos_next = find_position(*stack_b, max_idx - 1);
	else
		pos_next = -1;
	if (pos_next != -1 && is_closer(pos_next, pos_max, size_b))
	{
		move_to_top_b(stack_b, pos_next);
		do_pa(stack_a, stack_b);
		pos_max = find_position(*stack_b, max_idx);
		move_to_top_b(stack_b, pos_max);
		do_pa(stack_a, stack_b);
		do_sa(stack_a);
	}
	else
	{
		move_to_top_b(stack_b, pos_max);
		do_pa(stack_a, stack_b);
	}
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	max_idx;

	while (*stack_b)
	{
		max_idx = find_highest_index(*stack_b);
		push_max_to_a(stack_a, stack_b, max_idx);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:39:35 by fjose-hi          #+#    #+#             */
/*   Updated: 2026/01/07 19:46:44 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_method(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size <= 1 || is_sorted(*stack_a))
		return ;
	if (stack_size == 2)
		do_sa(stack_a);
	else if (stack_size == 3)
		sort_3(stack_a);
	else if (stack_size == 4)
		sort_4(stack_a, stack_b);
	else if (stack_size == 5)
		sort_5(stack_a, stack_b);
//	else
//		sort(stack_a, stack_b);
}

int	find_lowest_index(t_stack *stack)
{
	int	lowest;

	if (!stack)
		return (-1);
	lowest = stack->index;
	while (stack)
	{
		if (stack->index < lowest)
			lowest = stack->index;
		stack = stack->next;
	}
	return (lowest);
}

int	find_position(t_stack *stack, int target_index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == target_index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

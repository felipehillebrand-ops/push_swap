/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_chunks_to_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:23:51 by fjose-hi          #+#    #+#             */
/*   Updated: 2026/01/12 21:15:38 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exists_in_chunk(t_stack *stack, int start, int end)
{
	while (stack)
	{
		if (stack->index >= start && stack->index < end)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	push_to_b(t_stack **stack_a, t_stack **stack_b, int start, int end)
{
	int	pos;
	int	size;

	size = ft_stacksize(*stack_a);
	if ((*stack_a)->index >= start && (*stack_a)->index < end)
	{
		do_pb(stack_a, stack_b);
		if ((*stack_b)->index < start + ((end - start) / 2))
			do_rb(stack_b);
	}
	else
	{
		pos = ft_find_first_in_chunk(*stack_a, start, end);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				do_ra(stack_a);
		}
		else
		{
			pos = size - pos;
			while (pos-- > 0)
				do_rra(stack_a);
		}
	}
}

void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
	int	chunk_start;
	int	chunk_end;
	int	total_size;

	total_size = ft_stacksize(*stack_a);
	chunk_start = 0;
	chunk_end = chunk_size;
	while (chunk_start < total_size)
	{
		if (chunk_end > total_size)
			chunk_end = total_size;
		while (exists_in_chunk(*stack_a, chunk_start, chunk_end))
			push_to_b(stack_a, stack_b, chunk_start, chunk_end);
		chunk_start += chunk_size;
		chunk_end += chunk_size;
	}
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	chunk_size;

	size = ft_stacksize(*stack_a);
	if (size <= 100)
		chunk_size = 19;
	else
		chunk_size = 55;
	if (chunk_size < 1)
		chunk_size = 1;
	push_chunks_to_b(stack_a, stack_b, chunk_size);
	push_back_to_a(stack_a, stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 23:20:15 by fjose-hi          #+#    #+#             */
/*   Updated: 2026/01/12 21:15:02 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	ft_find_first_in_chunk(t_stack *stack, int start, int end)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index >= start && stack->index < end)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}
/*
int	find_last_in_chunk(t_stack *stack, int start, int end)
{
	int	pos;
	int	last_pos;

	pos = 0;
	last_pos = -1;
	while (stack)
	{
		if (stack->index >= start && stack->index < end)
			last_pos = pos;
		stack = stack->next;
		pos++;
	}
	return (last_pos);
}
*/

/*
void	ft_freelist(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
*/
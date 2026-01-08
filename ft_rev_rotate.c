/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:46:43 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/12/30 19:13:53 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rev_rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*before_tail;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tail = ft_stacklast(*stack);
	before_tail = ft_stackbeforelast(*stack);
	before_tail->next = NULL;
	tail->next = *stack;
	*stack = tail;
}

void	do_rra(t_stack **stack_a)
{
	ft_rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	do_rrb(t_stack **stack_b)
{
	ft_rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}

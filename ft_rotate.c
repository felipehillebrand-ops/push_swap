/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:46:31 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/12/30 18:11:02 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	tail = ft_stacklast(*stack);
	tail->next = tmp;
}

void	do_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	do_rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}

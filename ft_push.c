/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:46:39 by fjose-hi          #+#    #+#             */
/*   Updated: 2026/01/15 20:47:33 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	do_pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	ft_push(stack_b, stack_a);
	if (print)
		write(1, "pa\n", 3);
}

void	do_pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	ft_push(stack_a, stack_b);
	if (print)
		write(1, "pb\n", 3);
}

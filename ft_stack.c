/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 23:20:15 by fjose-hi          #+#    #+#             */
/*   Updated: 2026/01/08 21:06:17 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newnode(int content)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->index = -1;
	node->next = NULL;
	return (node);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_stackbeforelast(t_stack *stack)
{
	if (!stack || !stack->next)
		return (NULL);
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

int	ft_stacksize(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = ft_stacklast(*stack);
	last->next = new;
}

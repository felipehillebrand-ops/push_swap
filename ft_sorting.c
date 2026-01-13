/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:39:35 by fjose-hi          #+#    #+#             */
/*   Updated: 2026/01/12 20:37:21 by fjose-hi         ###   ########.fr       */
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
	else if (stack_size <= 5)
		sort_4_or_5(stack_a, stack_b);
	else
		chunk_sort(stack_a, stack_b);
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

int	find_highest_index(t_stack *stack)
{
	int	highest;

	if (!stack)
		return (-1);
	highest = stack->index;
	while (stack)
	{
		if (stack->index > highest)
			highest = stack->index;
		stack = stack->next;
	}
	return (highest);
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

/*
#include <stdio.h> 

int	main(void)
{
	t_stack *stack = ft_newnode(3);
    stack->next = ft_newnode(2);
    stack->next->next = ft_newnode(1);

	if (is_sorted(stack))
        printf("A lista já está ordenada!\n");
    else
	{
        printf("A lista não está ordenada!\n");
	}
	ft_freelist(stack);
	return (0);
}
*/
/*
#include <stdio.h>void	free_stack(t_stack **stack)

static void print_sort_method(t_stack *stack_a, int stack_size)
{
	if (stack_size <= 1 || is_sorted(stack_a))void	free_stack(t_stack **stack)
		printf("Lista já está ordenada ou tem só 1 elemento\n");
	else if (stack_size == 2)
		printf("Método usado: sa\n");
	else if (stack_size == 3)void	free_stack(t_stack **stack)
		printf("Método usado: sort_3\n");
	else if (stack_size == 4)
		printf("Método usado: sort_4\n");
	else if (stack_size == 5)
		printf("Método usado: sort_5\n");
	else
		printf("Método usado: sort\n");
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		stack_size;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		ft_stackadd_back(&stack_a, ft_newnode(ft_atol(argv[i])));
		i++;
	}
	stack_size = ft_stacksize(stack_a);
	print_sort_method(stack_a, stack_size);
	sort_method(&stack_a, &stack_b, stack_size);
}
*/

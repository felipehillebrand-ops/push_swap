/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:30:59 by fjose-hi          #+#    #+#             */
/*   Updated: 2026/01/08 20:30:56 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_lower(t_stack *stack, int value)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->content < value)
			count++;
		stack = stack->next;
	}
	return (count);
}

void	assign_index(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		current->index = count_lower(stack, current->content);
		current = current->next;
	}
}

static t_stack	*init_stack_from_array(char **args)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = 0;
	while (args[i])
	{
		ft_stackadd_back(&stack, ft_newnode(ft_atol(args[i])));
		i++;
	}
	return (stack);
}

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack;
	char	**args;

	stack = NULL;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		stack = init_stack_from_array(args);
		free_arg(args);
	}
	else
		stack = init_stack_from_array(av + 1);
	return (stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	parse_init(ac, av);
	stack_a = init_stack(ac, av);
	stack_b = NULL;
	assign_index(stack_a);
	size = ft_stacksize(stack_a);
	sort_method(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

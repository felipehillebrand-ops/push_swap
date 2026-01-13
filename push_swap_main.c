/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:10:00 by jules             #+#    #+#             */
/*   Updated: 2024/01/13 19:10:00 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (ac < 2)
		return (0);
	parse_init(ac, av);
	stack_a = init_stack(ac, av);
	stack_b = NULL;
	assign_index(stack_a);
	size = ft_stacksize(stack_a);
	sort_method(&stack_a, &stack_b, size);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}

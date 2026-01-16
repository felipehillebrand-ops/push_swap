/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:44:18 by fjose-hi          #+#    #+#             */
/*   Updated: 2026/01/16 16:21:28 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static void	error_exit_bonus(t_stack **a, t_stack **b)
{
	ft_free_stack(a);
	ft_free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	exec_instruction(t_stack **a, t_stack **b, char *command)
{
	if (!ft_strcmp(command, "sa\n"))
		do_sa(a, 0);
	else if (!ft_strcmp(command, "sb\n"))
		do_sb(b, 0);
	else if (!ft_strcmp(command, "ss\n"))
		do_ss(a, b, 0);
	else if (!ft_strcmp(command, "pa\n"))
		do_pa(a, b, 0);
	else if (!ft_strcmp(command, "pb\n"))
		do_pb(a, b, 0);
	else if (!ft_strcmp(command, "ra\n"))
		do_ra(a, 0);
	else if (!ft_strcmp(command, "rb\n"))
		do_rb(b, 0);
	else if (!ft_strcmp(command, "rr\n"))
		do_rr(a, b, 0);
	else if (!ft_strcmp(command, "rra\n"))
		do_rra(a, 0);
	else if (!ft_strcmp(command, "rrb\n"))
		do_rrb(b, 0);
	else if (!ft_strcmp(command, "rrr\n"))
		do_rrr(a, b, 0);
	else
		error_exit_bonus(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (ac < 2)
		return (0);
	parse_init(ac, av);
	stack_a = init_stack(ac, av);
	stack_b = NULL;
	line = get_next_line(0);
	while (line)
	{
		if (!line)
			break ;
		exec_instruction(&stack_a, &stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(stack_a) && ft_stacksize(stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}

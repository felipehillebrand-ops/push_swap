/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checklist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by jules             #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (ft_issign(str[i]) && str[i + 1])
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	have_duplicates(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atol(args[i]) == ft_atol(args[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_correct_input(char **args)
{
	int		i;
	long	num;

	i = 0;
	while (args[i])
	{
		if (!str_is_number(args[i]))
			return (0);
		num = ft_atol(args[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		i++;
	}
	if (have_duplicates(args))
		return (0);
	return (1);
}

void	parse_init(int ac, char **av)
{
	char	**args;

	if (ac < 2)
		error_exit();
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args || !args[0] || !is_correct_input(args))
		{
			free_arg(args);
			error_exit();
		}
		free_arg(args);
	}
	else
	{
		if (!is_correct_input(av + 1))
			error_exit();
	}
}

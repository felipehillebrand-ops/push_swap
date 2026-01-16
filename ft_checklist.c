/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checklist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:24:37 by fjose-hi          #+#    #+#             */
/*   Updated: 2026/01/09 17:37:32 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_is_number(char *av)
{
	int	i;

	i = 0;
	if (!av || !av[0])
		return (0);
	if (ft_issign(av[i]) && av[i + 1])
		i++;
	if (!ft_isdigit(av[i]))
		return (0);
	while (ft_isdigit(av[i]))
		i++;
	if (av[i])
		return (0);
	return (1);
}

static int	str_is_zero(char *av)
{
	int	i;

	i = 0;
	if (!av || !av[0])
		return (0);
	if (ft_issign(av[i]) && av[i + 1])
		i++;
	if (av[i] != '0')
		return (0);
	while (av[i] && av[i] == '0')
		i++;
	if (av[i])
		return (0);
	return (1);
}

static int	have_duplicates(char **av)
{
	int		i;
	int		j;
	long	n1;
	long	n2;

	i = 0;
	while (av[i])
	{
		n1 = ft_atol(av[i]);
		j = i + 1;
		while (av[j])
		{
			n2 = ft_atol(av[j]);
			if (n1 == n2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_correct_input(char **av)
{
	int		i;
	int		nb_zeros;
	long	n;

	i = 0;
	nb_zeros = 0;
	if (!av || !av[0])
		return (0);
	while (av[i])
	{
		if (!str_is_number(av[i]))
			return (0);
		n = ft_atol(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			return (0);
		nb_zeros += str_is_zero(av[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (have_duplicates(av))
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
		if (!args || !args[0])
		{
			free_arg(args);
			error_exit();
		}
		if (!is_correct_input(args))
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
/*
#include <stdio.h>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        write(2, "Error\n", 6);
        return 1;
    }
	parse_init(ac, av);
	printf("Entrada válida\n");
    return (0);
}
*/
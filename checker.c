/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:00:00 by jules             #+#    #+#             */
/*   Updated: 2024/01/13 19:25:00 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

// A robust get_next_line implementation, adapted to use the project's Libft
static char	*read_and_save(int fd, char *save)
{
	char	*buffer;
	char	*temp;
	int		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		temp = save;
		save = ft_strjoin(save, buffer);
		free(temp);
	}
	free(buffer);
	return (save);
}

static char	*get_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*new_save(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free(save);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!save)
		save = ft_strdup("");
	save = read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = get_line(save);
	save = new_save(save);
	return (line);
}

// Forward declarations for core logic functions
void	swap(t_stack **stack);
void	push(t_stack **src, t_stack **dest);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);

// Checker logic - calls the non-printing core functions
static void	execute_op(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strncmp(op, "sa\n", 3))
		swap(a);
	else if (!ft_strncmp(op, "sb\n", 3))
		swap(b);
	else if (!ft_strncmp(op, "ss\n", 3))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strncmp(op, "pa\n", 3))
		push(b, a);
	else if (!ft_strncmp(op, "pb\n", 3))
		push(a, b);
	else if (!ft_strncmp(op, "ra\n", 3))
		rotate(a);
	else if (!ft_strncmp(op, "rb\n", 3))
		rotate(b);
	else if (!ft_strncmp(op, "rr\n", 3))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strncmp(op, "rra\n", 4))
		rev_rotate(a);
	else if (!ft_strncmp(op, "rrb\n", 4))
		rev_rotate(b);
	else if (!ft_strncmp(op, "rrr\n", 4))
	{
		rev_rotate(a);
		rev_rotate(b);
	}
	else
		error_exit();
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
		execute_op(&stack_a, &stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:33:19 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/21 19:26:29 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;
	t_list	d;
	t_list	*current;

	a.next = &b;
	b.next = &c;
	c.next = NULL;
	d.next = NULL;
	a.content = "Felipe";
	b.content = "Jose";
	c.content = "Hillebrand";
	d.content = "Ferreira";
	current = &a;
	ft_lstadd_front(&current, &d);
	while (current != NULL)
	{
		printf("%s ", (char *)current->content);
		current = current->next;
	}
	printf("\n");
	return (0);
}
*/

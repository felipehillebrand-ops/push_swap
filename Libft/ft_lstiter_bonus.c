/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:23:48 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/22 14:45:51 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if (!lst || !f)
		return ;
	current = lst;
	while (current)
	{
		f(current->content);
		current = current->next;
	}
}
/*
#include <stdio.h>

void	ft_print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	t_list	*d;

	a = ft_lstnew(ft_strdup("Primeiro"));
	b = ft_lstnew(ft_strdup("Segundo"));
	c = ft_lstnew(ft_strdup("Terceiro"));
	d = ft_lstnew(ft_strdup("Quarto"));
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = NULL;
	ft_lstiter(a, ft_print_content);
	ft_lstclear(&a, free);
	return (0);
}
*/

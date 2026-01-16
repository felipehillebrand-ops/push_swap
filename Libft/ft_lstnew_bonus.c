/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:54:51 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/21 17:32:26 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	a;
	t_list	b;
	t_list	c;
	t_list	*d;
	t_list	*current;
	char	*nome;

	a.next = &b;
	b.next = &c;
	c.next = NULL;
	a.content = "Felipe";
	b.content = "Jose";
	c.content = "Hillebrand";
	nome = "Ferreira";
	d = ft_lstnew(nome);
	c.next = &(*d);
	current = &a;
	while (current != NULL)
	{
		printf("%s ", (char *)current->content);
		current = current->next;
	}
	return (0);
}
*/

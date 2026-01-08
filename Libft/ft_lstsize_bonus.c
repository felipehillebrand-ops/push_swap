/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:21:49 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/21 18:42:11 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	t_list	*d;

	a = ft_lstnew("Primeiro");
	b = ft_lstnew("Segundo");
	c = ft_lstnew("Terceiro");
	d = ft_lstnew("Quarto");
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = NULL;
	printf("Tamanho da lista: %d\n", ft_lstsize(a));
	free(d);
	free(c);
	free(b);
	free(a);
	return (0);
}
*/

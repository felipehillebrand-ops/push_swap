/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:15:35 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/22 21:49:24 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
/*
#include <stdio.h>

void	delnode(void *node)
{
	free(node);
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
	printf("Conteúdo antes de ft_lstclear: ");
        printf("%s ", (char *)(a->content));
	printf("%s ", (char *)(b->content));
        printf("%s ", (char *)(c->content));
        printf("%s \n", (char *)(d->content));
	ft_lstclear(&a, delnode);
	a = NULL;
	b = NULL;
	c = NULL;
	d = NULL;
	printf("Após ft_lstclear: Nós deletados com sucesso!\n");
	return (0);
}
*/

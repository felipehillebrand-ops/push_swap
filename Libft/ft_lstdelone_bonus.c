/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:05:25 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/22 15:31:07 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
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

	a = ft_lstnew(ft_strdup("42"));
	if (!a)
	{
		printf("Falha na alocação do nó!\n");
		return (1);
	}
	printf("Conteúdo do nó antes de ft_lstdelone: %s\n", (char *)(a->content));
	ft_lstdelone(a, delnode);
	a = NULL;
	printf("Após ft_lstdelone: Nodo deletado com sucesso!\n");
	return (0);
}
*/

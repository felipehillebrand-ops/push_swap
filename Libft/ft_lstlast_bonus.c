/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:42:40 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/21 19:33:16 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>

int     main(void)
{
        t_list  *a;
        t_list  *b;
        t_list  *c;
        t_list  *d;

        a = ft_lstnew("Primeiro");
        b = ft_lstnew("Segundo");
        c = ft_lstnew("Terceiro");
        d = ft_lstnew("Quarto");
        a->next = b;
        b->next = c;
        c->next = d;
        d->next = NULL;
        printf("Ultimo nó: %s\n", (char *)(ft_lstlast(a))->content);
        free(d);
        free(c);
        free(b);
        free(a);
        return (0);
}
*/

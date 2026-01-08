/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:00:57 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/21 19:26:08 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*
#include <stdio.h>

int     main(void)
{
        t_list  a;
        t_list  b;
        t_list  c;
        t_list  d;
        t_list  *current;

        a.next = &b;
        b.next = &c;
        c.next = NULL;
        d.next = NULL;
        a.content = "Felipe";
        b.content = "Jose";
        c.content = "Hillebrand";
        d.content = "Ferreira";
        current = &a;
        ft_lstadd_back(&current, &d);
        while (current != NULL)
        {
                printf("%s ", (char *)current->content);
                current = current->next;
        }
        printf("\n");
        return (0);
}
*/

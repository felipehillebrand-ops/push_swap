/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:12:30 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/22 21:31:52 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_obj;
	void	*new_content;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		new_obj = ft_lstnew(new_content);
		if (!new_obj)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_obj);
		lst = lst->next;
	}
	return (new_list);
}
/*
#include <stdio.h>

void	ft_print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s ", (char *)lst->content);
		lst = lst->next;
	}
	printf("\n");
}

void	*ft_dup_content(void *content)
{
	char	*str;

	str = ft_strdup((char *)content);
	*str = *str - 32;
	return (str);
}

void	ft_del_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*original;
	t_list	*mapped;

	original = ft_lstnew(ft_strdup("primeiro"));
	if (!original)
		return (1);
	ft_lstadd_back(&original, ft_lstnew(ft_strdup("segundo")));
	ft_lstadd_back(&original, ft_lstnew(ft_strdup("terceiro")));
	ft_lstadd_back(&original, ft_lstnew(ft_strdup("quarto")));
	printf("Original: ");
	ft_print_list(original);
	mapped = ft_lstmap(original, ft_dup_content, ft_del_content);
	printf("Mapped: ");
	ft_print_list(mapped);
	ft_lstclear(&original, ft_del_content);
	ft_lstclear(&mapped, ft_del_content);
	return (0);
}*/

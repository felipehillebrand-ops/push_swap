/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:53:42 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/15 16:59:16 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello, World!";
	unsigned int	i;
	unsigned int	limit;

	i = 0;
	limit = 13;
	printf("Antes do ft_bzero: %s\n", str);
	ft_bzero(str, 5);
	printf("Depois do ft_bzero: ");
	while (i < limit)
	{
		if (str[i] == 0)
			printf("\\0");
		else
			printf("%c", str[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/

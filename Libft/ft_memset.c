/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:21:45 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/15 14:48:12 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = (unsigned char)c;
	return (s);
}
/*
#include <stdio.h>

int	main(void)
{
	char	buffer[10];
	int	i;
       
	i = 0;
	ft_memset(buffer, 'X', 10);
	while (i < 10)
	{
		printf("%c ", buffer[i]);
		i++;
	}
	printf("\n");
	return (0);
}*/

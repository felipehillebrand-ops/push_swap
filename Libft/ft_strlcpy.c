/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:43:58 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/15 15:12:34 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (size != 0)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[] = "Hello, mundo!";
	char	dst[10];
	int	len;

	len = ft_strlcpy(dst, src, 10);
	printf("src: %s\n", src);
	printf("dst: %s\n", dst);
	printf("Tamanho da src: %d\n", len);
	if (len >= 10)
		printf("Aviso: a string foi truncada!\n");
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 20:02:39 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/24 17:08:11 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	uc;
	size_t			i;

	str = (unsigned char *) s;
	uc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == uc)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*strmchr;
	char	cmchr;
	size_t	lmchr;
	char	*rmchr;

	strmchr = "Arara azul";
	cmchr = 'a';
	lmchr = 10;
	rmchr = (char *)ft_memchr(strmchr, cmchr, lmchr);
	printf("\n---- Memchr tests ----\n");
	if (rmchr != NULL)
		printf("Caractere '%c' encontrado em: %ld\n", cmchr, rmchr - strmchr);
	else
		printf("Caractere '%c' não encontrado.\n", cmchr, lmchr);
	return (0);
}
*/

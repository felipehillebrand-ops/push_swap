/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:14:24 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/24 17:24:20 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (cc == '\0')
		return ((char *) &s[i]);
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*strchr;
	char		cchr;
	char		*rchr;

	strchr = "Arara azul";
	cchr = 'a';
	rchr = ft_strchr(strchr, cchr);
	printf("\n---- Strchr tests ----\n");
	if (rchr != NULL)
		printf("Caractere '%c' encontrado em: %ld\n", cchr, rchr - strchr);
	else
		printf("Caractere '%c' não encontrado na string.\n", cchr);
	rchr = ft_strchr(strchr, '\0');
	if (rchr != NULL)
		printf("Caractere nulo '\\0' encontrado em: %ld\n", rchr - strchr);
	return (0);
}
*/

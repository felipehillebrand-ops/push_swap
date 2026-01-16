/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:57:30 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/24 18:37:29 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*res;
	char			cc;

	cc = (char) c;
	res = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			res = (char *) &s[i];
		i++;
	}
	if (cc == '\0')
		res = (char *) &s[i];
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*strrchr;
	char	crchr;
	char	*rrchr;

	strrchr = "Arara azul";
	crchr = 'a';
	rrchr = ft_strrchr(strrchr, crchr);
	printf("\n---- Strrchr tests ----\n");
	if (rrchr != NULL)
		printf("Última ocorrência de '%c' em: \"%s\"\n", crchr, rrchr);
	else
		printf("Caractere '%c' não encontrado na string.\n", crchr);
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:31:45 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/17 16:31:34 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
#include <stdio.h>

int	main(void)
{
	char *original = "Olá, mundo!";
	char *copia;

	copia = ft_strdup(original);
	if (copia == NULL)
	{
		printf("Erro na alocação de memória.\n");
		return (1);
	}
	printf("Original: %s\n", original);
	printf("Cópia:    %s\n", copia);
	free(copia);
	return (0);
}
*/

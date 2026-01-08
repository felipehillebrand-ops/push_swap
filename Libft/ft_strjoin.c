/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:46:51 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/18 22:23:22 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = 0;
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1 = "Arara ";
	char	*s2 = "azul";
	char	*result;

	result = ft_strjoin(s1, s2);
	if (result)
	{
		printf("Resultado: %s\n", result);
		free(result);
	}
	else
		printf("Falha na alocação de memória. \n");
	return (0);
}
*/

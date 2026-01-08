/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:53:05 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/19 16:29:56 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *principal, const char *sub, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (sub[0] == 0)
		return ((char *) principal);
	while (principal[i] && i < len)
	{
		while (principal[i + j] == sub[j] && principal[i + j] && i + j < len)
		{
			j++;
			if (sub[j] == 0)
				return ((char *) principal + i);
		}
		i++;
		j = 0;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*tstr;
	const char	*sstr;
        char    *rstr;

	tstr = "Arara Azul";
	sstr = "ara";
	rstr = ft_strnst(tstr, sstr, 5);
	if (rstr)
		printf("Encontrado '%s' em '%s' em: \"%s\"\n", sstr, tstr, rstr);
	else
		printf("'%s' não encontrado em '%s\n", sstr, tstr);
}
*/

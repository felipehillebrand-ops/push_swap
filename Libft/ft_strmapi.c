/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:00:44 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/19 20:39:50 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (s == NULL || f == NULL)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
char    sample_function(unsigned int i, char c)
{
        i = 0;
        return (c - 32);
}

#include <stdio.h>

int	main(void)
{
	const char	*strmapi;
	char	*rmapi;

	strmapi = "araraazul";
        rmapi = ft_strmapi(strmapi, sample_function);
	if (rmapi)
	{
		printf("%s\n", rmapi); 
		free(rmapi);
	}
	return (0);
}
*/

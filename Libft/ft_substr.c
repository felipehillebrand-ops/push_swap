/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:21:45 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/18 22:02:35 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*original;
	unsigned int	start;
	size_t	len;
	char	*substr;

        original = "Arara azul";
        start = 6;
        len = 3;
        substr = ft_substr(original, start, len);
	if (!substr)
	{
		printf("Erro na alocação de memória!\n");
		return (1);
	}
	printf("Original: %s\n", original);
	printf("Substring (start=%u, len=%zu): %s\n", start, len, substr);
	free(substr);
	start = 50;
	substr = ft_substr(original, start, len);
	printf("Substring com start fora da string: '%s'\n", substr);
	free(substr);
	start = 7;
	len = 4;
	substr = ft_substr(original, start, len);
	printf("Substring com len maior que o resto: '%s'\n", substr);
	free(substr);
	return (0);
}
*/

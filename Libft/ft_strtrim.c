/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:56:36 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/19 17:34:39 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_trim(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (to_trim(set, s1[i]))
		i++;
	while (to_trim(set, s1[j]))
		j--;
	return (ft_substr(s1, i, j - (i - 1)));
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*s1trim;
	const char	*settrim;
	char	*rtrim;

	s1trim = "c1db@bArara azuldb@1c@1d";
	settrim = "1bc@d";
	rtrim = ft_strtrim(s1trim, settrim);
	if (rtrim)
	{
		printf("Trimmed string: '%s'\n", rtrim);
		free(rtrim);
	}
	else
		printf("Trimming failed\n");
	return (0);
}
*/

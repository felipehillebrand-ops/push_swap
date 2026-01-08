/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:35:08 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/19 20:36:44 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;	

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

void	sample_function2(unsigned int i, char *c)
{
	i = 0;
	*c = *c + 32;
}

int	main(void)
{
	char	striteri[] = "ARARAAZUL";

	ft_striteri(striteri, sample_function2);
	printf("%s\n", striteri);
	return (0);
}
*/

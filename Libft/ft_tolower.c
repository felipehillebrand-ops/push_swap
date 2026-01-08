/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:40:46 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/15 22:00:45 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	int	tl;

	tl = 69;
	printf("Antes: %c\n", tl);
	printf("Depois: %c\n", ft_tolower(tl));
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:25:10 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/15 22:00:25 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	int	tu;

	tu = 100;
        printf("Antes: %c\n", tu);
	printf("Depois: %c\n", ft_toupper(tu));
	return (0);
}
*/

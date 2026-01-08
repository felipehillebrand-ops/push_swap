/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:26:47 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/15 14:22:40 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	ch;
	       
	ch = 'F';
	if (ft_isalpha(ch))
		printf("%c é uma letra.\n", ch);
	else
		printf("%c não é uma letra.\n", ch);
	return (0);
}
*/

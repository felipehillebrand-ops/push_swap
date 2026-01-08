/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 19:41:09 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/15 14:24:00 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int     main(void)
{
        char    ch;
               
        ch = '7';
        if (ft_isdigit(ch))
                printf("%c é um dígito .\n", ch);
        else
                printf("%c não é um dígito.\n", ch);
        return (0);
}
*/

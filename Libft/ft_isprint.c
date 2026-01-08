/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:35:37 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/15 14:24:25 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int     main(void)
{
        int    ch;
               
        ch = 13;
        if (ft_isprint(ch))
                printf("%c é imprímivel.\n", ch);
        else
                printf("%c não é imprímivel.\n", ch);
        return (0);
}
*/

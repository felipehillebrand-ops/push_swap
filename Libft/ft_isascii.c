/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:06:56 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/15 14:23:16 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int     main(void)
{
        int    ch;
               
        ch = 68;
        if (ft_isascii(ch))
                printf("%c é ASCII.\n", ch);
        else
                printf("%c não é ASCII.\n", ch);
        return (0);
}
*/

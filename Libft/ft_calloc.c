/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:19:07 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/17 20:16:59 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i < count * size)
		tmp[i++] = 0;
	return (tmp);
}
/*
#include <stdio.h>

int	main(void)
{
	int	*arr;
	size_t	i;
	size_t	n;

	i = 0;
	n = 6;
	arr = (int *)ft_calloc(n, sizeof(int));
	if (arr == NULL)
	{
		printf("Falha na alocação de memória.\n");
		return (1);
	}
	printf("Valores após ft_calloc:\n");
	while (i < n)
	{
		printf("arr[%zu] = %d\n", i, arr[i]);
		i++;
	}
	free(arr);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjose-hi <fjose-hi@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:45:50 by fjose-hi          #+#    #+#             */
/*   Updated: 2025/10/18 15:58:16 by fjose-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
			ft_putnbr_fd(n, fd);
		}
		else if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			c = (n % 10) + '0';
			write(fd, &c, 1);
		}
		else
		{
			c = n + '0';
			write(fd, &c, 1);
		}
	}
}
/*
#include <fcntl.h>

int	main(void)
{
	ft_putnbr_fd(42, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(-2147483648, 1);
        write(1, "\n", 1);
	ft_putnbr_fd(-1234, 1);
        write(1, "\n", 1);
	ft_putnbr_fd(0, 1);
        write(1, "\n", 1);

    int fd = open("saida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	        return 1;
	ft_putnbr_fd(2025, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(-42, fd);
	write(fd, "\n", 1);
	close(fd);
	return (0);
}*/

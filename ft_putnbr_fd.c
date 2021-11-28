/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwhateve <cwhateve@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:08:58 by cwhateve          #+#    #+#             */
/*   Updated: 2021/11/11 19:08:58 by cwhateve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int m)
{
	if (m < 0)
	{
		m = (-1) * m;
	}
	return (m);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
		ft_putchar_fd('-', fd);
	nbr = (unsigned int)ft_abs(n);
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwhateve <cwhateve@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:20:55 by cwhateve          #+#    #+#             */
/*   Updated: 2021/11/11 16:20:55 by cwhateve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	d;
	int		abs;

	d = 0;
	abs = 1;
	while (*str == ' ' || *str == '\t' || \
	*str == '\r' || *str == '\n' || *str == '\f' || *str == '\v')
		str ++;
	if (*str == '-')
	{
		abs = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str) && *str)
	{
		d = (d * 10) + (*str++ - 48);
		if (d > 2147483647 && abs == 1)
			return (-1);
		if (d > 2147483648 && abs == -1)
			return (0);
	}
	return (d * abs);
}

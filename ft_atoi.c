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

static int	ft_isspace_atoi(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	num;

	i = 0;
	minus = 1;
	num = 0;
	while (ft_isspace_atoi(str[i]))
		i = i + 1;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i = i + 1;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + str[i] - '0';
		i = i + 1;
	}
	return (num * minus);
}

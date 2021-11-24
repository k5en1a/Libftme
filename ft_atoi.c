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

static int	finalize(int res, int dnum, int sign)
{
	if (res > INT_MAX / 10)
	{
		if (sign > 0)
			return (INT_MAX);
		else
			return (INT_MIN);
	}
	if (sign > 0)
	{
		if (dnum > (INT_MAX % 10))
			return (INT_MAX);
		else
			return (res * 10 + dnum);
	}
	else if (dnum > -(INT_MIN % 10))
		return (INT_MIN);
	else
		return (-res * 10 - dnum);
}

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int		res;
	int		sign;
	int		dnum;

	res = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			sign = -1;
	while (ft_isdigit(*nptr))
	{
		dnum = *nptr++ - '0';
		if (res >= (INT_MAX / 10))
			return (finalize(res, dnum, sign));
		res = res * 10 + dnum;
	}
	return (res * sign);
}

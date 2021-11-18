/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwhateve <cwhateve@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:10:02 by cwhateve          #+#    #+#             */
/*   Updated: 2021/11/10 20:10:02 by cwhateve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void
	*ft_memmove(void *dst, const void *src, size_t n)
{
	int	i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			// *(char *)(dst + i) = *(char *)(src + i);
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}

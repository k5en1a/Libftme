/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwhateve <cwhateve@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:07:26 by cwhateve          #+#    #+#             */
/*   Updated: 2021/11/11 16:07:26 by cwhateve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	needle_n;

	needle_n = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack && n >= needle_n)
	{
		if (*haystack == *needle && !(ft_memcmp(haystack, needle, needle_n)))
			return ((char *)haystack);
		haystack++;
		n--;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwhateve <cwhateve@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:05:57 by cwhateve          #+#    #+#             */
/*   Updated: 2021/11/03 19:05:57 by cwhateve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	idx;
	char			*tmp;

	if (!s || !f)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!(tmp))
		return (NULL);
	idx = 0;
	while (idx < (ft_strlen((char *)s)))
	{
		tmp[idx] = f(idx, s[idx]);
		idx++;
	}
	tmp[idx] = '\0';
	return (tmp);
}

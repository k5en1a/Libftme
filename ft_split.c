/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwhateve <cwhateve@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:28:26 by cwhateve          #+#    #+#             */
/*   Updated: 2021/11/15 21:28:26 by cwhateve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

struct s_dc
{
	size_t	count;
	size_t	storage;
};

static void	*freefabric(void **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}

static struct s_dc	word_count(const char *str, char sep)
{
	struct s_dc	ret;

	ret.count = 0;
	ret.storage = 0;
	while (*str)
	{
		while (*str == sep)
			str++;
		if (*str)
			ret.count++;
		while (*str && *str != sep)
		{
			str++;
			ret.storage++;
		}
	}
	ret.storage += ret.count;
	return (ret);
}

static void	populate(char **t, const char *src, char sep, size_t cnt)
{
	char	*dst;
	size_t	w;

	w = 0;
	dst = (char *)(t + cnt + 1);
	while (w < cnt)
	{
		t[w] = dst;
		while (*src && *src != sep)
			*dst++ = *src++;
		dst++;
		while (*src == sep)
			src++;
		w++;
	}
}

char	**ft_split_sm(const char *str, char sep)
{
	struct s_dc		dc;
	char			**table;

	while (*str && *str == sep)
		str++;
	dc = word_count(str, sep);
	table = (char **)ft_calloc(dc.storage + (dc.count + 1) * sizeof(void *), 1);
	if (table && dc.count)
	{
		populate(table, str, sep, dc.count);
	}
	return (table);
}

char	**ft_split(char const *str, char sep)
{
	unsigned int	i;
	const char		*end;
	char			**tab;

	tab = (char **)ft_calloc(word_count(str, sep).count + 1, sizeof(char *));
	if (tab)
	{
		i = 0;
		end = str;
		while (*end)
		{
			while (*end == sep)
				str = ++end;
			while (*end && *end != sep)
				end++;
			if (end > str)
			{
				tab[i] = ft_substr(str, 0, end - str);
				if (tab[i++] == NULL)
					return (freefabric((void **)tab));
			}
		}
	}
	return (tab);
}

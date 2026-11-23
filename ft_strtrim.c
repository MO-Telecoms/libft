/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohodeh <mohodeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:16:31 by mohodeh           #+#    #+#             */
/*   Updated: 2026/11/23 22:45:50 by mohodeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	while (s1[start] != '\0' && in_set(s1[start], set))
		start++;
	end = 0;
	while (s1[end] != '\0')
		end++;
	while (end > start && in_set(s1[end - 1], set))
		end--;
	p = malloc(end - start + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		p[i] = s1[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

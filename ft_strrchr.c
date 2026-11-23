/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohodeh <mohodeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:16:28 by mohodeh           #+#    #+#             */
/*   Updated: 2026/11/23 22:46:05 by mohodeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*found;

	i = 0;
	found = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			found = (char *)s + i;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (found);
}

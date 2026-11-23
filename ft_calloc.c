/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohodeh <mohodeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:14:54 by mohodeh           #+#    #+#             */
/*   Updated: 2026/11/23 22:40:24 by mohodeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	size_t			total;
	size_t			i;

	if (count != 0 && size > (size_t)-1 / count)
		return (NULL);
	total = count * size;
	p = malloc(total);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < total)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}

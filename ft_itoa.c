/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohodeh <mohodeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:15:09 by mohodeh           #+#    #+#             */
/*   Updated: 2026/11/23 22:53:47 by mohodeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	digit_count(unsigned int nb)
{
	size_t	len;

	len = 1;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	put_digits(char *p, unsigned int nb, size_t len)
{
	size_t	i;

	i = len;
	while (i > 0)
	{
		i--;
		p[i] = (nb % 10) + '0';
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	char			*p;
	unsigned int	nb;
	size_t			len;
	int				neg;

	neg = (n < 0);
	if (neg)
		nb = -(unsigned int)n;
	else
		nb = (unsigned int)n;
	len = digit_count(nb) + neg;
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	p[len] = '\0';
	put_digits(p, nb, len);
	if (neg)
		p[0] = '-';
	return (p);
}

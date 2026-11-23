/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohodeh <mohodeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:15:56 by mohodeh           #+#    #+#             */
/*   Updated: 2026/11/23 22:39:01 by mohodeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	put_unsigned(unsigned int nb, int fd)
{
	char	c;

	if (nb >= 10)
		put_unsigned(nb / 10, fd);
	c = (nb % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		write(fd, "-", 1);
		nb = -(unsigned int)n;
	}
	else
		nb = (unsigned int)n;
	put_unsigned(nb, fd);
}

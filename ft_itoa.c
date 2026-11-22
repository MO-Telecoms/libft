#include <stdlib.h>
#include "libft.h"

static size_t	digit_count(unsigned int nb)
{
	size_t len;

	len = 1;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char *p;
	unsigned int nb;
	size_t len;
	size_t i;
	int neg;

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
	i = len;
	do
	{
		i--;
		p[i] = (nb % 10) + '0';
		nb /= 10;
	} while (nb != 0);
	if (neg)
		p[0] = '-';
	return (p);
}

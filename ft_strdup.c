#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *p;
	size_t len;
	size_t i;

	len = 0;
	while (s1[len] != '\0')
		len++;
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		p[i] = s1[i];
		i++;
	}
	return (p);
}

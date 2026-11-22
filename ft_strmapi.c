#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *p;
	size_t len;
	size_t i;

	len = 0;
	while (s[len] != '\0')
		len++;
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		p[i] = f((unsigned int)i, s[i]);
		i++;
	}
	p[len] = '\0';
	return (p);
}

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *p;
	size_t len1;
	size_t len2;
	size_t i;

	len1 = 0;
	while (s1[len1] != '\0')
		len1++;
	len2 = 0;
	while (s2[len2] != '\0')
		len2++;
	p = malloc(len1 + len2 + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		p[len1 + i] = s2[i];
		i++;
	}
	p[len1 + len2] = '\0';
	return (p);
}

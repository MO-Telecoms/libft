#include <stdlib.h>
#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t count;
	size_t i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	free_all(char **arr, size_t n)
{
	while (n > 0)
	{
		n--;
		free(arr[n]);
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char **arr;
	size_t words;
	size_t w;
	size_t i;
	size_t start;
	size_t len;
	size_t k;

	words = count_words(s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	w = 0;
	while (w < words)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		len = i - start;
		arr[w] = malloc(len + 1);
		if (arr[w] == NULL)
		{
			free_all(arr, w);
			return (NULL);
		}
		k = 0;
		while (k < len)
		{
			arr[w][k] = s[start + k];
			k++;
		}
		arr[w][len] = '\0';
		w++;
	}
	arr[w] = NULL;
	return (arr);
}

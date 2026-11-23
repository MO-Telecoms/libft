/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohodeh <mohodeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:16:01 by mohodeh           #+#    #+#             */
/*   Updated: 2026/11/23 22:34:49 by mohodeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

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

static char	*word_dup(char const *s, size_t len)
{
	char	*word;
	size_t	k;

	word = malloc(len + 1);
	if (word == NULL)
		return (NULL);
	k = 0;
	while (k < len)
	{
		word[k] = s[k];
		k++;
	}
	word[len] = '\0';
	return (word);
}

static int	fill_words(char **arr, char const *s, char c, size_t words)
{
	size_t	w;
	size_t	i;
	size_t	start;

	w = 0;
	i = 0;
	while (w < words)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		arr[w] = word_dup(s + start, i - start);
		if (arr[w] == NULL)
		{
			free_all(arr, w);
			return (0);
		}
		w++;
	}
	arr[w] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	words;

	words = count_words(s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (arr == NULL)
		return (NULL);
	if (!fill_words(arr, s, c, words))
		return (NULL);
	return (arr);
}

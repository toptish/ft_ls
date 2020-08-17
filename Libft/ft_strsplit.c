/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:33:56 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/05 19:49:36 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char		*ft_fill_word(char const *s, char c, size_t *i)
{
	char	*word;
	size_t	index;

	if (!(word = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	index = 0;
	while (s[*i] != c && s[*i])
	{
		word[index] = s[*i];
		index++;
		*i = *i + 1;
	}
	word[index] = '\0';
	while (s[*i] == c && s[*i])
		*i = *i + 1;
	return (word);
}

static char		**ft_free(char **s, size_t j)
{
	while (j--)
		free(s[j]);
	free(s[j]);
	free(s);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**result;
	size_t	words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * ((words + 1)))))
		return (NULL);
	i = 0;
	while (s[i] == c && s[i])
		i++;
	j = 0;
	while (s[i] && j < words)
	{
		if (!(result[j] = ft_fill_word(s, c, &i)))
			return (ft_free(result, j));
		j++;
	}
	result[j] = NULL;
	return (result);
}

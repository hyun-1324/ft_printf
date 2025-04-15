/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 11:33:55 by donheo            #+#    #+#             */
/*   Updated: 2025/03/25 15:51:00 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*word_up(const char *start, size_t len)
{
	char	*word;

	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

static void	free_all(char **split, int i)
{
	while (i--)
		free(split[i]);
	free(split);
}

static int	copy_words(char const *s, char c, char **split)
{
	int			i;
	const char	*start;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			split[i] = word_up(start, s - start);
			if (!split[i])
			{
				free_all(split, i);
				return (0);
			}
			i++;
		}
		else
			s++;
	}
	split[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**split;

	if (!s)
		return (NULL);
	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	if (!copy_words(s, c, split))
		return (NULL);
	return (split);
}

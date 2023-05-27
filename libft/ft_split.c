/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gparpine <gparpine@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:52:41 by gparpine          #+#    #+#             */
/*   Updated: 2023/05/04 09:39:37 by gparpine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(char *str, char c);
static int	wordlen(const char *s, char c);

/*
 * Splits the string 's' into an array of substrings, using the character 'c' as
 * a delimiter. The array size is determined by the number of substrings. Each
 * substring in the array is created using memory allocation with ft_substr
 * function.
 */
char	**ft_split(char const *s, char c)
{
	int		num_words;
	char	**words;
	int		word_len;
	int		i;

	if (s == NULL)
		return (NULL);
	num_words = count_words((char *)s, c);
	words = malloc(sizeof(char *) * (num_words + 1));
	if (!words)
		return (NULL);
	i = 0;
	while (i < num_words)
	{
		while (*s == c)
			s++;
		word_len = wordlen(s, c);
		words[i] = ft_substr(s, 0, word_len);
		s += word_len;
		i++;
	}
	words[num_words] = NULL;
	return (words);
}

static int	count_words(char *str, char c)
{
	int	num_words;
	int	flag;

	num_words = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			num_words++;
			flag = 1;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (num_words);
}

static int	wordlen(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

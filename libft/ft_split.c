/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:28:05 by frbeyer           #+#    #+#             */
/*   Updated: 2023/11/23 17:33:57 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static void	next_word(char **word, unsigned int *word_len, char c)
{
	size_t	i;

	*word += *word_len;
	*word_len = 0;
	i = 0;
	while (**word && **word == c)
		(*word)++;
	while ((*word)[i])
	{
		if ((*word)[i] == c)
			return ;
		(*word_len)++;
		i++;
	}
}

static char	**ft_free(char **p)
{
	size_t	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	unsigned int		words;
	unsigned int		i;
	unsigned int		word_len;
	char				**p;
	char				*tmp;

	words = count_words(s, c);
	p = malloc((words + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	i = 0;
	word_len = 0;
	tmp = (char *)s;
	while (i < words)
	{
		next_word(&tmp, &word_len, c);
		p[i] = malloc(sizeof(char) * (word_len + 1));
		if (!p[i])
			return (ft_free(p));
		ft_strlcpy(p[i], tmp, word_len + 1);
		i++;
	}
	p[i] = NULL;
	return (p);
}

// int	main(void)
// {
// 	char	**string = ft_split("1 0 0 -1 -1 0 1 1 0 0 ", ' ');
// 	int 	i;

// 	i = 0;
// 	while (i < 10)
// 	{
// 		printf("%s", string[i++]);
// 	}
// }

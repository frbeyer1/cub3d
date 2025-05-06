/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:17:09 by frbeyer           #+#    #+#             */
/*   Updated: 2024/05/17 17:08:02 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return (i);
}

char	*ft_str_chr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_str_join(char *str_rest, char *buff)
{
	size_t	i;
	size_t	j;
	char	*p;

	if (!buff)
		return (NULL);
	if (!str_rest)
	{
		str_rest = (char *) malloc(1 * sizeof(char));
		if (!str_rest)
			return (NULL);
		str_rest[0] = 0;
	}
	p = malloc((ft_str_len(str_rest) + ft_str_len(buff) + 1) * sizeof(char));
	if (!p)
		return (free(str_rest), NULL);
	i = -1;
	j = 0;
	while (str_rest[++i] != '\0')
		p[i] = str_rest[i];
	while (buff[j] != '\0')
		p[i++] = buff[j++];
	p[ft_str_len(str_rest) + ft_str_len(buff)] = '\0';
	free(str_rest);
	return (p);
}

char	*get_linie(char *str_rest)
{
	int		i;
	char	*str;

	i = 0;
	while (str_rest[i] != '\n' && str_rest[i])
		i++;
	if (str_rest[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (str_rest[i] != '\n' && str_rest[i])
	{
		str[i] = str_rest[i];
		i++;
	}
	if (str_rest[i] == '\n')
	{
		str[i] = str_rest[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_str_rest(char *str_rest)
{
	int		i;
	int		j;
	int		rest_len;
	char	*str;

	i = 0;
	while (str_rest[i] != '\n' && str_rest[i] != '\0')
		i++;
	if (str_rest[i] == '\0')
		return (free(str_rest), NULL);
	if (str_rest[i] == '\n')
		i++;
	rest_len = ft_strlen(str_rest) - i;
	if (rest_len == 0)
		return (free(str_rest), NULL);
	str = malloc(sizeof(char) * rest_len + 1);
	if (!str)
		return (free(str_rest), NULL);
	j = 0;
	while (str_rest[i] != '\0')
		str[j++] = str_rest[i++];
	str[j] = '\0';
	free(str_rest);
	return (str);
}

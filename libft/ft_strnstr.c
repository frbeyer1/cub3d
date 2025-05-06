/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:28:15 by frbeyer           #+#    #+#             */
/*   Updated: 2023/06/12 15:41:20 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

static char	is_string(const char *str, const char *to_find,
						int pos, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_strlen(to_find);
	if (len < j)
		return (0);
	while (to_find[i] != '\0' && len > 0)
	{
		if (str[pos + i] != to_find[i])
			return (0);
		i++;
		len--;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len > 0)
	{
		if (is_string(haystack, needle, i, len))
			return ((char *)(haystack + i));
		i++;
		len--;
	}
	return (0);
}

// int	main(void)
// {
// 	const char	str[50] = "hallo was geht";
// 	const char	to_find[50] = "c";
// 	int		len;

// 	len = -1;
// 	printf ("%s\n", strnstr(str, to_find, len));
// 	printf ("%s\n", ft_strnstr(str, to_find, len));
// 	return (0);
// }

// gcc -Wall -Wextra -Werror ft_strnstr.c
// ft_strnstr(haystack, "a", -1)
// ft_strnstr(haystack, "c", -1)
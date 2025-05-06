/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:05:30 by frbeyer           #+#    #+#             */
/*   Updated: 2023/05/30 17:42:09 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			j;
	unsigned int	k;
	char			*p;

	j = 0;
	k = ft_strlen((char *)s);
	if (start > k && s != (void *)0)
	{
		p = ft_calloc(1, sizeof(char));
		if (!p)
			return (NULL);
		return (p);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (j < len)
	{
		p[j] = s[start + j];
		j++;
	}
	p[len] = (char) '\0';
	return (p);
}

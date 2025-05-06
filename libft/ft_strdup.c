/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:47:34 by frbeyer           #+#    #+#             */
/*   Updated: 2023/05/26 14:23:56 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen((char *)s1);
	p = malloc((j + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (i <= j)
	{
		p[i] = s1[i];
		i++;
	}
	return (p);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strdup("hallo"));
// 	printf("%s\n", strdup("hallo"));
// }

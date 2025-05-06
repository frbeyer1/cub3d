/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:36:16 by frbeyer           #+#    #+#             */
/*   Updated: 2023/05/24 17:34:29 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen((char *)src);
	if (dstsize == 0)
		return (j);
	while (dstsize > 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	dst[i] = '\0';
	return (j);
}

// int main(void)
// {
// 	const char	*src = "lorem ipsum";
// 	char	dest[5];

// 	printf("%zu\n", ft_strlcpy(dest, src, sizeof(dest)));
// 	printf("%s\n", dest);
// 	printf("%lu\n", strlcpy(dest, src, sizeof(dest)));
// 	printf("%s\n", dest);
// 	return (0);
// }

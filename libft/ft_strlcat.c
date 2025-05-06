/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:55:49 by frbeyer           #+#    #+#             */
/*   Updated: 2023/05/25 15:10:18 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int	i;
	size_t			len;
	size_t			len2;

	len = ft_strlen(dst);
	len2 = ft_strlen((char *)src);
	i = 0;
	if (dstsize == 0)
		return (len2 + dstsize);
	while (src[i] != '\0' && (len + i) < (dstsize - 1))
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	if (dstsize < len)
		return (len2 + dstsize);
	return (len + len2);
}

// int main(void) 
// {
//     char dest[10] = "a";
//     const char *src = "lorem ipsum dolor sit amet";

// 	printf("%hhd\n", ft_strlcat(dest, src, 1));
// 	printf("%s\n", dest);
// 	char dest2[10] = "a";
//     const char *src2 = "lorem ipsum dolor sit amet";

//     printf("%zu\n", strlcat(dest2, src2, 1));
// 	printf("%s\n", dest2);
//     return 0;
// }

/*gibt länge von verketteten strings wieder und fügt sie im hintergrund 
innerhalb angegebener länge zusammen*/
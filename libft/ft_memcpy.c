/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:23:42 by frbeyer           #+#    #+#             */
/*   Updated: 2023/05/26 16:20:42 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char		*dest_p;
	const unsigned char	*src_p;

	dest_p = (unsigned char *)dest;
	src_p = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (len > 0)
	{
		*dest_p++ = *src_p++;
		len--;
	}
	return (dest);
}

// int main(void)
// {
// 	// const char	*src = "0";
// 	// char	dest[3];

// 	printf("%s\n", ft_memcpy((void *)0, (void *)0, 3));
// 	// printf("%s\n", dest);
// 	printf("%s\n", memcpy((void *)0, (void *)0, 3));
// 	// printf("%s\n", dest);
// 	return (0);
// }

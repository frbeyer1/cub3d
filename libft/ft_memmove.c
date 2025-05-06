/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:38:59 by frbeyer           #+#    #+#             */
/*   Updated: 2023/05/24 11:44:50 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_move;
	const unsigned char	*src_move;

	dst_move = (unsigned char *)dst;
	src_move = (const unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
		while (len--)
			*(dst_move + len) = *(src_move + len);
	else
		while (len--)
			*dst_move++ = *src_move++;
	return (dst);
}

// int	main(void)
// {
// 	int	src[5] = {1, 2, 3, 4, 5};
// 	int	src2[5] = {1, 2, 3, 4, 5};
// 	int	i;

// 	i = 0;
// 	ft_memmove(src + 2, src, sizeof(int) * 3);
// 	printf("ft_memmove\n");
// 	while (i < 5)
// 	{
// 		printf("s[%d] = %d\n", i ,src[i]);
// 		i++;
// 	}
// 	i = 0;
// 	printf("%s\n", memmove(src2 + 2, src2, sizeof(int) * 3));
// 	printf("memmove\n");
// 	while (i < 5)
// 	{
// 		printf("s[%d] = %d\n", i ,src[i]);
// 		i++;
// 	}
// 	return (0);
// }

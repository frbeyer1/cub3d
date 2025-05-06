/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:58:39 by frbeyer           #+#    #+#             */
/*   Updated: 2023/05/25 15:35:07 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*ptr1 == *ptr2 && n > 1)
	{
		ptr1++;
		ptr2++;
		n--;
	}
	return (*ptr1 - *ptr2);
}

// int	main(void)
// {
// 	char	*str1 = "zyxbcdefgh";
// 	char	*str2 = "abcdefgxyz";

// 	printf("%d\n", ft_memcmp(str1, str2, 1));
// 	printf("%d\n", memcmp(str1, str2, 1));
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:59:11 by frbeyer           #+#    #+#             */
/*   Updated: 2023/05/23 15:33:57 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t;
	unsigned char	d;

	t = (unsigned char *)s;
	d = (unsigned char)c;
	while (n)
	{
		if (*t == d)
			return (t);
		t++;
		n--;
	}
	return (0);
}

// int	main(void)
// {
// 	char	str[] = {'a', 'b', 'c', 'd', 'e'};

// 	char	*pos = memchr(str, 'b', 5);
// 	char	*skrr = ft_memchr(str, 'b', 5);
// 	printf("%c\n", skrr[0]);
// 	printf("%c\n", pos[0]);
// 	return (0);
// }

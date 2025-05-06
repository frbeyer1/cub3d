/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:41:51 by frbeyer           #+#    #+#             */
/*   Updated: 2023/05/25 11:33:48 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*d;

	d = b;
	while (len > 0)
	{
		*d++ = (unsigned char)c;
		len--;
	}
	return (b);
}

// int	main(void)
// {
// 	void *test = NULL;

// 	printf ("%s\n", ft_memset(&test, 'a', 5));
// 	printf ("%s\n", memset(&test, 'a', 5));
// 	return (0);
// }

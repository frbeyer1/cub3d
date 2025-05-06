/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:34:43 by frbeyer           #+#    #+#             */
/*   Updated: 2023/05/24 11:45:17 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*t;

	t = (unsigned char *)s;
	while (n > 0)
	{
		*t++ = 0;
		n--;
	}
}

// int	main(void)
// {
// 	char	test[] = "lolkacka";
// 	size_t	len;

// 	len = 5;

// 	printf("%s\n", test);
// 	ft_bzero(test, len);
// 	printf("%s\n", test);
// 	return (0);
// }

/*gcc -Wall -Wextra -Werror ft_bzero.c*/

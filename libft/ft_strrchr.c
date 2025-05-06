/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:49:33 by frbeyer           #+#    #+#             */
/*   Updated: 2023/05/30 17:56:04 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[i]);
	while (i > 0)
	{
		if (s[i] == (char) c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	if (s[i] == (char) c)
		return ((char *)&s[i]);
	return (0);
}

// int	main(void)
// {
// 	const char	*str = "Hello, World! asidufg q";

// 	printf("%s\n", ft_strrchr(str, 'o'));
// 	printf("%s\n", strrchr(str, 'o'));
// 	return (0);
// }

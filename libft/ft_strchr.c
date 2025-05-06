/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:47:09 by frbeyer           #+#    #+#             */
/*   Updated: 2023/05/30 16:47:53 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *)&s[i]);
	return (0);
}

// int	main(void)
// {
// 	const char	*str = "teste";

// 	printf("%s\n", ft_strchr(str, 'e'));
// 	printf("%s\n", strchr(str, 'e'));
// 	return (0);
// }

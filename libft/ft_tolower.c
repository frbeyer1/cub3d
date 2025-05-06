/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:44:52 by frbeyer           #+#    #+#             */
/*   Updated: 2023/05/24 11:37:51 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
	}
	return (c);
}

// int	main(void)
// {
// 	char c = 'A';

// 	printf("%c\n", ft_tolower(c));
// 	return (0);
// }
/*gcc -Wall -Wextra -Werror ft_tolower.c*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:35:28 by frbeyer           #+#    #+#             */
/*   Updated: 2023/05/25 15:27:02 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks if letter or number

#include <ctype.h>
#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')
		&& (c < '0' || c > '9'))
		return (0);
	else
		return (1);
}

// int	main(void)
// {
//     char ch1 = 'A';
//     char ch2 = '2';

// 	printf("%d\n", ft_isalnum(ch2));
// 	printf("%d\n", isalnum(ch2));
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:04:25 by frbeyer           #+#    #+#             */
/*   Updated: 2023/05/25 15:26:58 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks if letter

#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z'))
		return (0);
	else
		return (1);
}

// int	main(void)
// {
//     char ch1 = 'A';
//     char ch2 = '1';

// 	printf("%d\n", ft_isalpha(ch2));
// 	printf("%d\n",isalpha(ch2));
// 	return (0);
// }

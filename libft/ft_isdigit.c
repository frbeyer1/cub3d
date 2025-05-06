/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:22:26 by frbeyer           #+#    #+#             */
/*   Updated: 2023/05/16 16:24:22 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isdigit(int c)
{
	if ((c < '0' || c > '9'))
		return (0);
	else
		return (1);
}

// int	main(void)
// {
//     char ch1 = 'A';
//     char ch2 = '2';

// 	printf("%d\n", ft_isdigit(ch2));
// 	printf("%d\n", isdigit(ch2));
// 	return (0);
// }

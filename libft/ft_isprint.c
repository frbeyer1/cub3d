/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:25:03 by frbeyer           #+#    #+#             */
/*   Updated: 2023/05/16 16:28:59 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isprint(int c)
{
	if ((c < 32 || c > 126))
		return (0);
	else
		return (1);
}

// int	main(void)
// {
//     char ch1 = 'A';
//     char ch2 = 127;

// 	printf("%d\n", ft_isprint(ch1));
// 	printf("%d\n", isprint(ch1));
// 	return (0);
// }

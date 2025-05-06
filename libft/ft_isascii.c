/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:08:52 by frbeyer           #+#    #+#             */
/*   Updated: 2023/05/16 16:22:14 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int c)
{
	if ((c < 0 || c > 127))
		return (0);
	else
		return (1);
}

// int	main(void)
// {
//     char ch1 = 127;
//     char ch2 = 128;

// 	printf("%d\n", ft_isascii(ch1));
// 	printf("%d\n",isascii(ch1));
// 	printf("%d\n", ft_isascii(ch2));
// 	printf("%d\n",isascii(ch2));
// 	return (0);
// }

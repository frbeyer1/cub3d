/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:44:13 by frbeyer           #+#    #+#             */
/*   Updated: 2023/07/05 10:14:32 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	length(int n)
{
	int	digit;

	digit = 0;
	if (!n)
		return (digit);
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static char	*ft_result(int len, int sign, int n)
{
	char	*result;

	result = malloc((len + sign + 1) * sizeof(char));
	if (!result)
		return (result);
	result[len + sign] = '\0';
	if (sign == 1)
		*(result + 0) = '-';
	while (len > 0)
	{
		result[len + sign - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int				len;
	int				sign;
	char			*result;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	len = length(n);
	result = ft_result(len, sign, n);
	return (result);
}

// int	main()
// {
// 	printf("%s\n", ft_itoa(-100000000));
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:11:40 by frbeyer           #+#    #+#             */
/*   Updated: 2023/06/12 15:17:43 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int	main(void)
// {
// 	char s1[] = "";
// 	char s2[] = "";
// 	int	n;

// 	n = 1;
// 	// ft_strncmp(s1, s2, n);
// 	printf("%d\n", strncmp(s1, s2, n));
// 	printf("%d\n", ft_strncmp(s1, s2, n));
// 	return (0);
// }

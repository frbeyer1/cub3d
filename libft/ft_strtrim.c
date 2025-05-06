/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:17:12 by frbeyer           #+#    #+#             */
/*   Updated: 2023/06/10 16:33:43 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	is_set(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_s1;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	start_s1 = 0;
	while (s1[start_s1])
		if (is_set(s1[start_s1], set))
			start_s1++;
	else
		break ;
	if (start_s1 == len_s1)
		return (ft_strdup(""));
	while (s1[len_s1 - 1])
		if (is_set(s1[len_s1 - 1], set))
			len_s1--;
	else
		break ;
	return (ft_substr(s1, start_s1, len_s1 - start_s1));
}

// int	main(void)
// {
// 	printf("%s\n", ft_strtrim("++-++++halloa+", "+-"));
// }

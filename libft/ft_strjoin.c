/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:29:49 by frbeyer           #+#    #+#             */
/*   Updated: 2023/06/26 15:11:19 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	p_len;
	char	*p;

	p_len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	p = malloc((p_len) * sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, ft_strlen((char *)s1) + 1);
	ft_strlcat(p, s2, p_len);
	return (p);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strjoin("hal", "lo"));
// }

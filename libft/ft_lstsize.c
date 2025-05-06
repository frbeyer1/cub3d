/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:27:31 by frbeyer           #+#    #+#             */
/*   Updated: 2023/06/05 12:41:03 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	lenght;

	lenght = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		lenght++;
	}
	return (lenght);
}

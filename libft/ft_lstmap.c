/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:43:28 by frbeyer           #+#    #+#             */
/*   Updated: 2023/06/12 14:28:48 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new_lst;

	new_lst = (void *)0;
	while (lst != NULL)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
		{
			ft_lstclear(&new_lst, del);
			return (new_lst);
		}
		ft_lstadd_back(&new_lst, tmp);
		lst = lst->next;
	}
	return (new_lst);
}

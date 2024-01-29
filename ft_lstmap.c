/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:34:55 by anmedyns          #+#    #+#             */
/*   Updated: 2024/01/12 16:21:39 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst_node;
	t_list	*head_node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst_node = ft_lstnew(f(lst -> content));
	head_node = new_lst_node;
	while (lst -> next)
	{
		lst = lst -> next;
		if (!(lst -> content))
			del(lst -> content);
		new_lst_node -> next = ft_lstnew(f(lst -> content));
		if (!new_lst_node -> next)
		{
			ft_lstclear(&head_node, del);
			return (NULL);
		}
		new_lst_node = new_lst_node -> next;
	}
	return (head_node);
}

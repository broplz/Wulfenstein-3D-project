/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <hcherrie@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:12:16 by hcherrie          #+#    #+#             */
/*   Updated: 2020/11/17 01:12:18 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newhead;

	if (!lst)
		return (NULL);
	newlst = ft_lstnew(f(lst->content));
	if (newlst == NULL)
		return (NULL);
	newhead = newlst;
	while (lst->next)
	{
		lst = lst->next;
		newlst->next = ft_lstnew(f(lst->content));
		if (newlst->next == NULL)
		{
			ft_lstclear(&newhead, del);
			return (NULL);
		}
		newlst = newlst->next;
	}
	newlst->next = NULL;
	return (newhead);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <hcherrie@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:12:07 by hcherrie          #+#    #+#             */
/*   Updated: 2020/11/17 01:12:08 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *list)
{
	size_t	count;

	count = 0;
	if (!list)
		return (0);
	while (list->next != NULL)
	{
		list = list->next;
		count++;
	}
	count++;
	return ((int)count);
}

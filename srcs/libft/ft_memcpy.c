/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <hcherrie@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:12:10 by hcherrie          #+#    #+#             */
/*   Updated: 2020/11/17 01:12:11 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	d = dst;
	s = src;
	i = 0;
	if (dst == 0 && src == 0)
		return (dst);
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
